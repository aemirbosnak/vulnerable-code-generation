//Falcon-180B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // maximum length of each line in the file
#define MAX_FILE_NAME_LENGTH 50 // maximum length of the file name

struct Person {
    char name[MAX_LINE_LENGTH];
    int age;
    char address[MAX_LINE_LENGTH];
};

int main() {
    FILE *fp;
    char filename[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    struct Person person;
    int count = 0;

    // ask the user to enter the file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    // open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open the file.\n");
        exit(1);
    }

    // read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        count++;

        // parse the line into name, age, and address
        char *token = strtok(line, ",");
        strcpy(person.name, token);
        token = strtok(NULL, ",");
        person.age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(person.address, token);

        // display the person's information
        printf("Person %d:\n", count);
        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
        printf("Address: %s\n", person.address);
        printf("\n");
    }

    // close the file
    fclose(fp);

    return 0;
}