//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define JSON_BUFFER_SIZE 1024

// Struct to hold JSON data
typedef struct {
    char *key;
    char *value;
} json_data_t;

// Function to parse JSON data
void parse_json(char *json_string, void (*callback)(json_data_t)) {
    // Initialize buffer and data structures
    char json_buffer[JSON_BUFFER_SIZE];
    json_data_t data;
    data.key = NULL;
    data.value = NULL;

    // Parse JSON string
    int i = 0;
    int j = 0;
    int in_string = 0;
    int in_key = 0;
    int in_value = 0;
    while (json_string[i]) {
        if (json_string[i] == '{') {
            in_key = 1;
        } else if (json_string[i] == '}') {
            in_key = 0;
            if (data.key && data.value) {
                callback(data);
                memset(&data, 0, sizeof(json_data_t));
            }
        } else if (json_string[i] == '"') {
            in_string =!in_string;
        } else if (json_string[i] == ':') {
            if (in_key) {
                in_key = 0;
                in_value = 1;
            }
        } else if (json_string[i] == ',') {
            if (in_value) {
                data.value[j] = '\0';
                callback(data);
                memset(&data, 0, sizeof(json_data_t));
                in_value = 0;
            }
        } else if (in_value &&!in_string) {
            if (j >= JSON_BUFFER_SIZE - 1) {
                fprintf(stderr, "Error: Value too long\n");
                exit(1);
            }
            json_buffer[j++] = json_string[i];
        }
        i++;
    }
    if (data.key && data.value) {
        callback(data);
    }
}

// Callback function to print JSON data
void print_json_data(json_data_t data) {
    printf("Key: %s, Value: %s\n", data.key, data.value);
}

// Main function
int main() {
    char json_string[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    parse_json(json_string, print_json_data);
    return 0;
}