//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_STRING_LENGTH 100

typedef struct {
    char* name;
    char* address;
    char* email;
    char* phone;
} Person;

int main() {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    char name[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];

    fp = fopen("csv_data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Person person;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strstr(line, ",") == NULL) {
            continue;
        }
        sscanf(line, "%s,%s,%s,%s", name, address, email, phone);
        person.name = (char*)malloc(sizeof(char) * strlen(name));
        person.address = (char*)malloc(sizeof(char) * strlen(address));
        person.email = (char*)malloc(sizeof(char) * strlen(email));
        person.phone = (char*)malloc(sizeof(char) * strlen(phone));
        strcpy(person.name, name);
        strcpy(person.address, address);
        strcpy(person.email, email);
        strcpy(person.phone, phone);
        printf("%s,%s,%s,%s\n", person.name, person.address, person.email, person.phone);
        free(person.name);
        free(person.address);
        free(person.email);
        free(person.phone);
    }
    fclose(fp);
    return 0;
}