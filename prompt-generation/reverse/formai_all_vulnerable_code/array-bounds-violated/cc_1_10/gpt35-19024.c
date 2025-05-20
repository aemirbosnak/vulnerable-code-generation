//FormAI DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define SPAM_THRESHOLD 0.7

int is_spam(char *email) {
    int    i, spam_count = 0, total_count = 0;
    double spam_probability;

    char cmd[MAXLINE], buf[MAXLINE], filename[] = "email.txt";
    FILE *fp;

    // Save email to file
    fp = fopen(filename, "w");
    fprintf(fp, "%s", email);
    fclose(fp);

    // Call external spam detection tool
    sprintf(cmd, "spamassassin %s", filename);
    fp = popen(cmd, "r");
    while (fgets(buf, MAXLINE, fp) != NULL) {
        if (strstr(buf, "SPAM")) {
            spam_count++;
        }
        total_count++;
    }
    pclose(fp);

    // Calculate spam probability
    spam_probability = (double) spam_count / total_count;

    return (spam_probability > SPAM_THRESHOLD) ? 1 : 0;
}

int main() {
    char email[MAXLINE];
    int  result;

    printf("Please enter an email: ");
    fgets(email, MAXLINE, stdin);

    // Remove newline character from email input
    email[strlen(email) - 1] = '\0';

    result = is_spam(email);
    if (result) {
        printf("This email is likely spam.\n");
    } else {
        printf("This email is not spam.\n");
    }

    return 0;
}