//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *address;
    char *phone;
    char *email;
    int experience;
} Person;

Person *parse_resume(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Person *person = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (person == NULL) {
            person = (Person *) malloc(sizeof(Person));
            person->name = NULL;
            person->address = NULL;
            person->phone = NULL;
            person->email = NULL;
            person->experience = 0;
        }

        if (strstr(line, "Name:")!= NULL) {
            char *name = strtok(line, " ");
            person->name = strdup(name);
        } else if (strstr(line, "Address:")!= NULL) {
            char *address = strtok(line, " ");
            person->address = strdup(address);
        } else if (strstr(line, "Phone:")!= NULL) {
            char *phone = strtok(line, " ");
            person->phone = strdup(phone);
        } else if (strstr(line, "Email:")!= NULL) {
            char *email = strtok(line, " ");
            person->email = strdup(email);
        } else if (strstr(line, "Experience:")!= NULL) {
            char *experience_str = strtok(line, " ");
            person->experience = atoi(experience_str);
        }
    }

    fclose(fp);
    return person;
}

void print_person(Person *person) {
    if (person == NULL) {
        printf("No person found.\n");
        return;
    }

    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
    printf("Phone: %s\n", person->phone);
    printf("Email: %s\n", person->email);
    printf("Experience: %d years\n", person->experience);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    Person *person = parse_resume(argv[1]);
    if (person!= NULL) {
        print_person(person);
        free(person->name);
        free(person->address);
        free(person->phone);
        free(person->email);
        free(person);
    }

    return 0;
}