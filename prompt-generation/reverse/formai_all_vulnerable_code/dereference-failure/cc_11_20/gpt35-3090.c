//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct representing a key-value pair in the JSON object
typedef struct {
    char* key;
    char* value;
} Pair;

// A struct representing a JSON object
typedef struct {
    int num_pairs;
    Pair* pairs;
} JSONObject;

// A function to parse a JSON object from a string
JSONObject parseJSON(char* json) {
    JSONObject object;
    object.num_pairs = 0;
    object.pairs = NULL;

    // Remove any leading/trailing whitespace
    while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') {
        json++;
    }
    char* end = json + strlen(json) - 1;
    while (end > json && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
        *end-- = '\0';
    }

    // The first non-whitespace character should be '{'
    if (*json != '{') {
        printf("Error: Expected '{', found '%c'\n", *json);
        exit(1);
    }
    json++;

    // Loop through the key-value pairs in the object
    while (*json != '}') {
        // Parse the key
        if (*json != '"') {
            printf("Error: Expected '\"', found '%c'\n", *json);
            exit(1);
        }
        json++;
        char* key_start = json;
        while (*json != '"') {
            json++;
        }
        *json = '\0';
        object.num_pairs++;
        object.pairs = (Pair*)realloc(object.pairs, object.num_pairs * sizeof(Pair));
        object.pairs[object.num_pairs - 1].key = key_start;

        // Find the ':' separator between key and value
        json++;
        while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') {
            json++;
        }
        if (*json != ':') {
            printf("Error: Expected ':', found '%c'\n", *json);
            exit(1);
        }
        json++;

        // Parse the value
        while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') {
            json++;
        }
        if (*json == '"') {
            // String value
            json++;
            char* value_start = json;
            while (*json != '"') {
                json++;
            }
            *json = '\0';
            object.pairs[object.num_pairs - 1].value = value_start;
        } else if (*json == '{') {
            // Object value (recurse)
            char* object_start = json;
            int depth = 0;
            do {
                if (*json == '{') {
                    depth++;
                } else if (*json == '}') {
                    depth--;
                }
                json++;
            } while (depth > 0);
            *--json = '\0'; // Overwrite the ending '}' character

            object.pairs[object.num_pairs - 1].value = (char*)malloc((json - object_start + 2) * sizeof(char));
            strcpy(object.pairs[object.num_pairs - 1].value, object_start);
            JSONObject nested_object = parseJSON(object.pairs[object.num_pairs - 1].value);
            object.pairs[object.num_pairs - 1].value = (char*)&nested_object;
        } else {
            // Numeric value
            char* value_start = json;
            while (*json != ',' && *json != '}') {
                json++;
            }
            char temp = *json;
            *json = '\0';
            object.pairs[object.num_pairs - 1].value = value_start;
            *json = temp;
        }

        // Move past the value and find the ',' or '}'
        while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') {
            json++;
        }
        if (*json == ',') {
            json++;
        }
    }

    return object;
}

int main() {
    char* json_string = "{\"name\":\"John\",\"age\":30,\"city\":{\"name\":\"New York\",\"population\":8398748}}";
    JSONObject object = parseJSON(json_string);

    printf("Name: %s\n", object.pairs[0].value);
    printf("Age: %s\n", object.pairs[1].value);
    JSONObject city = *(JSONObject*)object.pairs[2].value;
    printf("City: %s\n", city.pairs[0].value);
    printf("Population: %s\n", city.pairs[1].value);

    return 0;
}