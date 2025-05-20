//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

struct person {
    char *name;
    char *email;
    char *phone;
    int years_of_experience;
};

struct person parse_line(char *line) {
    struct person person = {0};
    char *token;
    int i = 0;

    // Name
    token = strtok(line, ",");
    if (token!= NULL) {
        person.name = strdup(token);
        i++;
    }

    // Email
    token = strtok(NULL, ",");
    if (token!= NULL) {
        person.email = strdup(token);
        i++;
    }

    // Phone
    token = strtok(NULL, ",");
    if (token!= NULL) {
        person.phone = strdup(token);
        i++;
    }

    // Years of experience
    token = strtok(NULL, ",");
    if (token!= NULL) {
        person.years_of_experience = atoi(token);
        i++;
    }

    // Make sure we parsed exactly 4 tokens
    if (i!= 4) {
        fprintf(stderr, "Error: Invalid line format\n");
        exit(1);
    }

    return person;
}

void print_person(struct person person) {
    printf("Name: %s\n", person.name);
    printf("Email: %s\n", person.email);
    printf("Phone: %s\n", person.phone);
    printf("Years of experience: %d\n", person.years_of_experience);
    printf("\n");
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    struct person person;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        person = parse_line(line);
        print_person(person);
    }

    fclose(fp);
    return 0;
}