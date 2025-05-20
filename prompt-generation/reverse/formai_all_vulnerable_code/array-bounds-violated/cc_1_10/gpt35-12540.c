//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Define a structure to hold xml data
struct xml_data {
    char tag[50];
    char attributes[50][50];
    char values[50][50];
    int attribute_count;
    char inner_text[100];
    struct xml_data* children[50];
    int child_count;
};

// Declare functions to parse xml data
struct xml_data* parse_xml_file(char* filename);
void trim(char* string);
void parse_attributes(struct xml_data* data, char* attribute_string);
void parse_tag(char* xml_string, struct xml_data* data);

// Main function to test xml parser
int main() {
    struct xml_data* data = parse_xml_file("example.xml");
    printf("Tag: %s\n", data->tag);
    printf("Attribute Count: %d\n", data->attribute_count);
    for (int i = 0; i < data->attribute_count; i++) {
        printf("Attribute %d: %s=%s\n", i+1, data->attributes[i], data->values[i]);
    }
    printf("Inner Text: %s\n", data->inner_text);
    printf("Child Count: %d\n", data->child_count);
    return 0;
}

// Function to parse xml file
struct xml_data* parse_xml_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found!");
        exit(1);
    }
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, file);
    struct xml_data* data = (struct xml_data*)malloc(sizeof(struct xml_data));
    parse_tag(buffer, data);
    while (fgets(buffer, MAX_SIZE, file)) {
        trim(buffer);
        if (strlen(buffer) == 0) continue;
        if (buffer[0] == '<') {
            struct xml_data* child = (struct xml_data*)malloc(sizeof(struct xml_data));
            parse_tag(buffer, child);
            data->children[data->child_count++] = child;
        }
        else if (buffer[0] == '/') {
            break;
        }
        else {
            strcat(data->inner_text, buffer);
        }
    }
    fclose(file);
    return data;
}

// Function to parse xml tag
void parse_tag(char* xml_string, struct xml_data* data) {
    char tag[50];
    int i = 0;
    while (xml_string[i] != '>') {
        tag[i] = xml_string[i];
        i++;
    }
    tag[i] = '\0';
    strcpy(data->tag, tag);
    char attribute_string[50];
    int j = 0;
    if (tag[strlen(tag)-1] != '/') {
        while (xml_string[i] != '\0') {
            attribute_string[j] = xml_string[i];
            i++;
            j++;
        }
        attribute_string[j-1] = '\0';
        parse_attributes(data, attribute_string);
    }
}

// Function to parse xml attributes
void parse_attributes(struct xml_data* data, char* attribute_string) {
    char attribute[50];
    char value[50];
    int i = 0, j = 0, k = 0;
    while (attribute_string[i] != '\0') {
        while (attribute_string[i] != '=') {
            attribute[j] = attribute_string[i];
            i++;
            j++;
        }
        attribute[j-1] = '\0';
        j = 0;
        i++;
        while (attribute_string[i] != '"' && attribute_string[i] != '\0') {
            value[k] = attribute_string[i];
            i++;
            k++;
        }
        value[k] = '\0';
        k = 0;
        i++;
        strcpy(data->attributes[data->attribute_count], attribute);
        strcpy(data->values[data->attribute_count], value);
        data->attribute_count++;
    }
}

// Function to trim leading and trailing whitespace
void trim(char* string) {
    int i = 0;
    while (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
        i++;
    }
    strcpy(string, &string[i]);
    int len = strlen(string);
    while (string[len-1] == ' ' || string[len-1] == '\t' || string[len-1] == '\n') {
        string[len-1] = '\0';
        len--;
    }
}