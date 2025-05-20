//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a struct for metadata
typedef struct metadata {
    char name[100];
    char author[100];
    int age;
    float salary;
} metadata;

// Function to extract metadata from a file
metadata* extractMetadata(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the name, author, and age
    char nameBuffer[100];
    char authorBuffer[100];
    int age;
    fscanf(file, "Name: %s\nAuthor: %s\nAge: %d", nameBuffer, authorBuffer, &age);

    // Allocate memory for the metadata struct
    metadata* metadataObj = (metadata*) malloc(sizeof(metadata));
    if (metadataObj == NULL) {
        fclose(file);
        return NULL;
    }

    // Read the salary
    float salary;
    fscanf(file, "Salary: %f", &salary);

    // Copy the values to the metadata struct
    strcpy(metadataObj->name, nameBuffer);
    strcpy(metadataObj->author, authorBuffer);
    metadataObj->age = age;
    metadataObj->salary = salary;

    // Close the file
    fclose(file);

    return metadataObj;
}

int main() {
    const char* filename = "metadata.txt";
    metadata* metadataObj = extractMetadata(filename);
    if (metadataObj!= NULL) {
        printf("Name: %s\nAuthor: %s\nAge: %d\nSalary: %f\n",
               metadataObj->name, metadataObj->author, metadataObj->age, metadataObj->salary);
        free(metadataObj);
    }
    return 0;
}