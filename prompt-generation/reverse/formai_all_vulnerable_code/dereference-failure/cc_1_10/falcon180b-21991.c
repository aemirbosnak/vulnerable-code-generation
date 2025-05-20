//Falcon-180B DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAILS 100

struct email {
    char *from;
    char *to;
    char *subject;
    char *body;
};

int read_config_file(char *filename, struct email *emails) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open config file.\n");
        return -1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (count >= MAX_EMAILS) {
            printf("Error: Reached maximum number of emails.\n");
            fclose(fp);
            return -1;
        }

        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: Invalid email format.\n");
            fclose(fp);
            return -1;
        }

        emails[count].from = strdup(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid email format.\n");
            fclose(fp);
            return -1;
        }

        emails[count].to = strdup(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid email format.\n");
            fclose(fp);
            return -1;
        }

        emails[count].subject = strdup(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid email format.\n");
            fclose(fp);
            return -1;
        }

        emails[count].body = strdup(token);

        count++;
    }

    fclose(fp);
    return count;
}

int send_email(struct email *email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s config_file\n", argv[0]);
        return -1;
    }

    char *config_file = argv[1];
    struct email emails[MAX_EMAILS];

    int num_emails = read_config_file(config_file, emails);

    for (int i = 0; i < num_emails; i++) {
        send_email(&emails[i]);
    }

    return 0;
}