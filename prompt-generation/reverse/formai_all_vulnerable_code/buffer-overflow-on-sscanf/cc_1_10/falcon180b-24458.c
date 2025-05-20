//Falcon-180B DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define MAX_WORD 100
#define MAX_SUBJECT 100

typedef struct {
    char from[MAX_LINE];
    char to[MAX_LINE];
    char subject[MAX_SUBJECT];
    char message[MAX_LINE];
} Email;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE];
    Email email;
    int i = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (i == 0) {
            sscanf(line, "From: %[^\r\n]", email.from);
        }
        else if (i == 1) {
            sscanf(line, "To: %[^\r\n]", email.to);
        }
        else if (i == 2) {
            sscanf(line, "Subject: %[^\r\n]", email.subject);
        }
        else {
            strcat(email.message, line);
            strcat(email.message, "\r\n");
        }
        i++;
    }

    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Message:\n%s", email.message);

    fclose(fp);
    return 0;
}