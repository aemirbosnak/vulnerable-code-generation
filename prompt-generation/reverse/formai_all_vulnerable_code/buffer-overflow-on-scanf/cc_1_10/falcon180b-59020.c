//Falcon-180B DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECTS 100
#define MAX_BODIES 500

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODIES];
} Email;

Email emails[MAX_EMAILS];
int num_emails;

void read_emails() {
    FILE *fp;
    char filename[50];
    int i;

    printf("Enter email filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    num_emails = 0;

    while (fscanf(fp, "%s %s", emails[num_emails].subject, emails[num_emails].body)!= EOF) {
        num_emails++;
    }

    fclose(fp);
}

void print_emails() {
    int i;

    for (i = 0; i < num_emails; i++) {
        printf("%d. Subject: %s\n", i+1, emails[i].subject);
        printf("Body:\n%s\n", emails[i].body);
        printf("\n");
    }
}

int main() {
    read_emails();
    print_emails();

    return 0;
}