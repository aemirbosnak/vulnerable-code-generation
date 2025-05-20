//Falcon-180B DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_SUBJECT 1024
#define MAX_BODY 102400

typedef struct {
    char *subject;
    char *body;
} email;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE];
    email email;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(2);
    }

    email.subject = (char *) malloc(MAX_SUBJECT);
    email.body = (char *) malloc(MAX_BODY);

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (strncasecmp(line, "Subject:", 8) == 0) {
            strcpy(email.subject, line + 9);
        } else if (strncasecmp(line, "Content-Type:", 13) == 0) {
            char *content_type = strtok(line + 14, ";");
            if (content_type!= NULL && strncasecmp(content_type, "text/plain", 10) == 0) {
                strcat(email.body, "\n");
                strcat(email.body, line + 14);
            }
        } else {
            strcat(email.body, line);
            strcat(email.body, "\n");
        }
    }

    fclose(fp);

    fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(3);
    }

    fprintf(fp, "Subject: %s\n", email.subject);
    fprintf(fp, "Content-Type: text/plain\n\n");
    fprintf(fp, "%s", email.body);

    fclose(fp);

    free(email.subject);
    free(email.body);

    return 0;
}