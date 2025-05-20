//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

typedef struct {
    char *name;
    int age;
    char *email;
    char *phone;
} Person;

typedef struct {
    Person *person;
    struct node *next;
} Node;

Node *head = NULL;

void addPerson(char *line) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = strtok(line, ",");
    person->age = atoi(strtok(NULL, ","));
    person->email = strtok(NULL, ",");
    person->phone = strtok(NULL, ",");

    Node *node = (Node *)malloc(sizeof(Node));
    node->person = person;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void display() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("Name: %s\n", temp->person->name);
        printf("Age: %d\n", temp->person->age);
        printf("Email: %s\n", temp->person->email);
        printf("Phone: %s\n", temp->person->phone);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        addPerson(line);
    }

    fclose(fp);

    display();

    return 0;
}