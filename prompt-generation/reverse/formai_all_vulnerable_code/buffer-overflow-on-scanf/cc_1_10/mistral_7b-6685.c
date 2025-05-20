//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100
#define MAX_LINES 100
#define MAX_FIELDS 10
#define MAX_TOTAL_CHAR 1000

struct ResumeData {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    char fields[MAX_FIELDS][MAX_TOTAL_CHAR];
};

void parseLine(char line[], struct ResumeData *data) {
    char field[MAX_TOTAL_CHAR];
    char *token;
    int i = 0, j = 0;

    strcpy(field, "");
    token = strtok(line, ": ");

    while (token != NULL) {
        if (i < MAX_FIELDS) {
            strncat(data->fields[i], token, MAX_TOTAL_CHAR - strlen(data->fields[i]) - 1);
            strcat(data->fields[i], ": ");
            i++;
        }

        token = strtok(NULL, ": ");
    }

    if (i == MAX_FIELDS && strlen(field) > 0) {
        strncat(data->fields[i], field, MAX_TOTAL_CHAR - strlen(data->fields[i]) - 1);
    }
}

int main() {
    char line[MAX_TOTAL_CHAR];
    char fileName[MAX_NAME_LEN];
    struct ResumeData data;
    FILE *fp;
    int i = 0, lines = 0;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    while (fgets(line, MAX_TOTAL_CHAR, fp) != NULL) {
        if (lines++ > 0) {
            parseLine(line, &data);
        }
    }

    printf("\nName: %s\n", data.name);
    printf("Phone: %s\n", data.phone);
    printf("Email: %s\n", data.email);

    for (i = 0; i < MAX_FIELDS && strlen(data.fields[i]) > 0; i++) {
        printf("Field %d: %s\n", i + 1, data.fields[i]);
    }

    fclose(fp);

    return 0;
}