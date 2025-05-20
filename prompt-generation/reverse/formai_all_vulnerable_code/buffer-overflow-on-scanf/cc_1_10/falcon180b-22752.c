//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1024
#define SUBJECT_SIZE 80
#define DATE_SIZE 30
#define FROM_SIZE 80
#define TO_SIZE 80
#define CC_SIZE 80
#define BCC_SIZE 80
#define BODY_SIZE 1024

typedef struct {
    char subject[SUBJECT_SIZE];
    char date[DATE_SIZE];
    char from[FROM_SIZE];
    char to[TO_SIZE];
    char cc[CC_SIZE];
    char bcc[BCC_SIZE];
    char body[BODY_SIZE];
} EMAIL;

void read_email(FILE *fp, EMAIL *email) {
    fseek(fp, 0L, SEEK_SET);
    fgets(email->subject, SUBJECT_SIZE, fp);
    fgets(email->date, DATE_SIZE, fp);
    fgets(email->from, FROM_SIZE, fp);
    fgets(email->to, TO_SIZE, fp);
    fgets(email->cc, CC_SIZE, fp);
    fgets(email->bcc, BCC_SIZE, fp);
    fgets(email->body, BODY_SIZE, fp);
}

void write_email(FILE *fp, EMAIL *email) {
    fprintf(fp, "Subject: %s\n", email->subject);
    fprintf(fp, "Date: %s\n", email->date);
    fprintf(fp, "From: %s\n", email->from);
    fprintf(fp, "To: %s\n", email->to);
    fprintf(fp, "Cc: %s\n", email->cc);
    fprintf(fp, "Bcc: %s\n", email->bcc);
    fprintf(fp, "Body: %s\n", email->body);
}

void display_email(EMAIL *email) {
    printf("Subject: %s\n", email->subject);
    printf("Date: %s\n", email->date);
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Cc: %s\n", email->cc);
    printf("Bcc: %s\n", email->bcc);
    printf("Body: %s\n", email->body);
}

int main() {
    FILE *fp;
    char filename[MAX_SIZE];
    EMAIL email;

    printf("Enter email filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_email(fp, &email);
    fclose(fp);

    display_email(&email);

    return 0;
}