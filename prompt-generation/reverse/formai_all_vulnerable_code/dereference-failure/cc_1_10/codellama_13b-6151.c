//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
// JSON Parser Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON structure
typedef struct JSON {
    char *type;
    char *key;
    char *value;
    struct JSON *left;
    struct JSON *right;
} JSON;

// Function to parse a JSON string
JSON *parseJSON(char *jsonString) {
    JSON *root = NULL;
    JSON *current = NULL;
    JSON *newJSON = NULL;
    char *type = NULL;
    char *key = NULL;
    char *value = NULL;
    int i = 0;

    while (jsonString[i] != '\0') {
        switch (jsonString[i]) {
            case '{':
                if (root == NULL) {
                    root = (JSON *)malloc(sizeof(JSON));
                    current = root;
                } else {
                    newJSON = (JSON *)malloc(sizeof(JSON));
                    current->left = newJSON;
                    current = newJSON;
                }
                current->type = "object";
                break;
            case '}':
                current = current->left;
                break;
            case '[':
                if (root == NULL) {
                    root = (JSON *)malloc(sizeof(JSON));
                    current = root;
                } else {
                    newJSON = (JSON *)malloc(sizeof(JSON));
                    current->left = newJSON;
                    current = newJSON;
                }
                current->type = "array";
                break;
            case ']':
                current = current->left;
                break;
            case '"':
                key = (char *)malloc(sizeof(char) * 100);
                i++;
                while (jsonString[i] != '"') {
                    key[strlen(key)] = jsonString[i];
                    i++;
                }
                key[strlen(key)] = '\0';
                current->key = key;
                break;
            case ':':
                i++;
                value = (char *)malloc(sizeof(char) * 100);
                while (jsonString[i] != ',') {
                    value[strlen(value)] = jsonString[i];
                    i++;
                }
                value[strlen(value)] = '\0';
                current->value = value;
                break;
            case ',':
                break;
            default:
                break;
        }
        i++;
    }

    return root;
}

// Function to print the JSON structure
void printJSON(JSON *root) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        printJSON(root->left);
    }

    printf("type: %s, key: %s, value: %s\n", root->type, root->key, root->value);

    if (root->right != NULL) {
        printJSON(root->right);
    }
}

int main() {
    char jsonString[1000] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JSON *root = parseJSON(jsonString);
    printJSON(root);

    return 0;
}