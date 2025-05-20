//Falcon-180B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char *name;
    int age;
} Person;

void load_file(FILE *fp, Person **people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        (*num_people)++;
        *people = realloc(*people, sizeof(Person) * (*num_people));
        Person *person = &(*people)[i];
        person->name = strdup(name);
        person->age = age;
        i++;
    }
}

void save_file(FILE *fp, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(fp, "%s,%d\n", people[i].name, people[i].age);
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return 1;
    }
    Person *people = NULL;
    int num_people = 0;
    load_file(fp, &people, &num_people);
    fclose(fp);
    printf("Number of people: %d\n", num_people);
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Failed to open file for writing.\n");
        return 1;
    }
    save_file(fp, people, num_people);
    fclose(fp);
    printf("File saved successfully.\n");
    return 0;
}