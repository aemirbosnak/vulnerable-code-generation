//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    int i, j, k, len, status, num, index;
    char key[BUFFER_SIZE];
    char value[BUFFER_SIZE];
    char json[BUFFER_SIZE];
    char c;

    // Read the JSON string
    printf("Enter the JSON string: ");
    fgets(json, BUFFER_SIZE, stdin);
    len = strlen(json);
    json[len - 1] = '\0';   // Remove the newline character

    // Remove all whitespace characters from the string
    index = 0;
    for(i = 0; i < len; i++) {
        if(!isspace(json[i])) {
            buffer[index++] = json[i];
        }
    }
    buffer[index] = '\0';
    len = index;

    // Check if the JSON string begins with a '{' and ends with a '}'
    if(json[0] != '{' || json[len - 1] != '}') {
        printf("Invalid JSON string. JSON string should begin with '{' and end with '}'.\n");
        return 0;
    }

    // Parse the JSON string
    i = 1;  // Start from the second character
    status = 0;  // 0 -> parsing key, 1 -> parsing value, 2 -> parsing comma
    while(i < len - 1) {
        c = buffer[i];

        if(status == 0) {  // Parsing key
            if(c == ':') {
                key[j] = '\0';
                j = 0;
                status = 1;
            } else {
                key[j++] = c;
            }
        } else if(status == 1) {  // Parsing value
            if(c == ',' || i == len - 2) {
                if(i == len - 2) {
                    value[j++] = c;
                }
                value[j] = '\0';
                j = 0;
                status = 2;
                
                // Check if value is a number
                if(isdigit(value[0])) {
                    num = atoi(value);
                    printf("%s: %d\n", key, num);
                } else {
                    printf("%s: %s\n", key, value);
                }
            } else {
                value[j++] = c;
            }
        } else if(status == 2) {  // Parsing comma
            if(c == '\"') {
                status = 0;
            }
        }

        i++;
    }

    return 0;
}