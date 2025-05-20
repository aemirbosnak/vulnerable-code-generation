//Falcon-180B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

void read_email(FILE *fp, char *subject, char *body) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strncmp(line, "Subject:", 8) == 0) {
            strcpy(subject, line + 8);
        } else if (strncmp(line, "Content-Type:", 13) == 0) {
            char *type = strtok(line + 13, ";");
            if (strcmp(type, "text/plain") == 0) {
                char *boundary = strtok(NULL, ";");
                while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL && strncmp(line, boundary, strlen(boundary))!= 0) {
                    strcat(body, line);
                }
                break;
            }
        }
    }
}

void send_email(FILE *fp, char *to, char *subject, char *body) {
    fprintf(fp, "To: %s\r\n", to);
    fprintf(fp, "Subject: %s\r\n", subject);
    fprintf(fp, "Content-Type: text/plain\r\n");
    fprintf(fp, "Content-Transfer-Encoding: 7bit\r\n\r\n");
    fprintf(fp, "%s", body);
}

int main() {
    char filename[100];
    printf("Enter the name of the email file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char to[100], subject[100], body[1000];
    read_email(fp, subject, body);
    fclose(fp);

    fp = fopen("email.txt", "w");
    if (fp == NULL) {
        printf("Error: could not create file.\n");
        return 1;
    }

    send_email(fp, "example@example.com", subject, body);
    fclose(fp);

    printf("Email sent successfully!\n");
    return 0;
}