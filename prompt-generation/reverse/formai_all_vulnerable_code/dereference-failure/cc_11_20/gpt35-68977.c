//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef struct {
    char name[MAX_JSON_SIZE];
    char value[MAX_JSON_SIZE];
} json_property;

typedef struct {
    char name[MAX_JSON_SIZE];
    int num_properties;
    json_property *properties;
} json_object;

json_object* parse_json(const char *json) {
    char buffer[MAX_JSON_SIZE];
    int buffer_pos = 0;
    int position = 0;

    while (isspace(json[position])) {
        ++position;
    }

    if (json[position++] != '{') {
        return NULL;
    }

    json_object *object = malloc(sizeof(json_object));
    strcpy(object->name, "");
    object->num_properties = 0;
    object->properties = malloc(sizeof(json_property));

    while (1) {
        while (isspace(json[position])) {
            ++position;
        }

        if (json[position] == '}') {
            break;
        }

        if (json[position] != '"') {
            free(object->properties);
            free(object);
            return NULL;
        }

        ++position;

        buffer_pos = 0;
        while (json[position] != '"') {
            if (buffer_pos >= MAX_JSON_SIZE - 1) {
                free(object->properties);
                free(object);
                return NULL;
            }

            buffer[buffer_pos++] = json[position++];
        }

        buffer[buffer_pos] = '\0';

        strcpy(object->properties[object->num_properties].name, buffer);

        ++position;

        while (json[position] != ':') {
            if (!isspace(json[position])) {
                free(object->properties);
                free(object);
                return NULL;
            }

            ++position;
        }

        ++position;

        while (isspace(json[position])) {
            ++position;
        }

        if (json[position] == '{') {
            object->properties[object->num_properties].value[0] = '\0';
            json_object *inner_object = parse_json(json + position);

            if (inner_object == NULL) {
                free(object->properties);
                free(object);
                return NULL;
            }

            sprintf(object->properties[object->num_properties].value, "{\"name\":\"%s\",\"properties\":[", inner_object->name);

            for (int i = 0; i < inner_object->num_properties; ++i) {
                char *comma = i == inner_object->num_properties - 1 ? "" : ",";
                sprintf(object->properties[object->num_properties].value + strlen(object->properties[object->num_properties].value), "{\"name\":\"%s\",\"value\":\"%s\"}%s", inner_object->properties[i].name, inner_object->properties[i].value, comma);
            }

            sprintf(object->properties[object->num_properties].value + strlen(object->properties[object->num_properties].value), "]}");
            free(inner_object->properties);
            free(inner_object);
        } else {
            buffer_pos = 0;
            while (json[position] != ',' && json[position] != '}') {
                if (buffer_pos >= MAX_JSON_SIZE - 1) {
                    free(object->properties);
                    free(object);
                    return NULL;
                }

                buffer[buffer_pos++] = json[position++];
            }

            buffer[buffer_pos] = '\0';
            strcpy(object->properties[object->num_properties].value, buffer);
        }

        ++object->num_properties;

        if (json[position] == ',') {
            ++position;
        }
    }

    object->properties = realloc(object->properties, sizeof(json_property) * object->num_properties);
    strcpy(object->name, "root");

    return object;
}

int main() {
    const char *example = "{\"name\":\"John\",\"age\":30,\"car\":{\"name\":\"Ford\",\"model\":\"Mustang\",\"year\":1964}}";
    json_object *parsed = parse_json(example);

    if (parsed != NULL) {
        printf("Parsed JSON:\n{\"name\":\"%s\",\"properties\":[\n", parsed->name);

        for (int i = 0; i < parsed->num_properties; ++i) {
            char *comma = i == parsed->num_properties - 1 ? "" : ",";
            printf("{\"name\":\"%s\",\"value\":\"%s\"}%s\n", parsed->properties[i].name, parsed->properties[i].value, comma);
        }

        printf("]}\n");

        free(parsed->properties);
        free(parsed);
    } else {
        printf("JSON parse error!\n");
    }

    return 0;
}