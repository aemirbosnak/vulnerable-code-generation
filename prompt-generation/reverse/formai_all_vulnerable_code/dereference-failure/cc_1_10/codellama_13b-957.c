//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: active
// JSON Parser example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a JSON object
typedef struct {
  char* key;
  char* value;
} JSON_Object;

// Function to parse a JSON string
void parse_json(char* json_string) {
  // Initialize variables
  char* key;
  char* value;
  int index = 0;
  int key_start = 0;
  int key_end = 0;
  int value_start = 0;
  int value_end = 0;

  // Loop through each character in the JSON string
  while (json_string[index] != '\0') {
    // If we encounter a double quote, set the start of the key
    if (json_string[index] == '"') {
      key_start = index;
    }
    // If we encounter a colon, set the end of the key and the start of the value
    else if (json_string[index] == ':') {
      key_end = index;
      value_start = index + 1;
    }
    // If we encounter another double quote, set the end of the value
    else if (json_string[index] == '"') {
      value_end = index;
    }
    // If we encounter a comma, we have reached the end of an object
    else if (json_string[index] == ',') {
      // Parse the key and value
      key = json_string + key_start + 1;
      key[key_end - key_start - 1] = '\0';
      value = json_string + value_start;
      value[value_end - value_start] = '\0';
      // Print the key and value
      printf("Key: %s\nValue: %s\n", key, value);
      // Reset the variables
      key_start = 0;
      key_end = 0;
      value_start = 0;
      value_end = 0;
    }
    index++;
  }
}

// Test the JSON parser with a sample JSON string
int main() {
  char* json_string = "{\"name\":\"John Doe\",\"age\":30,\"city\":\"New York\"}";
  parse_json(json_string);
  return 0;
}