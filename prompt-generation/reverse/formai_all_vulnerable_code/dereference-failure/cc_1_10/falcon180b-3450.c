//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define EMAIL_LENGTH 100
#define EMAIL_DOMAIN_LENGTH 50
#define SPAM_THRESHOLD 5
#define TRAIN_FILE "train.txt"
#define TEST_FILE "test.txt"

typedef struct {
    char email[EMAIL_LENGTH];
    int is_spam;
} Email;

Email train_data[1000];
int num_train_data = 0;

Email test_data[1000];
int num_test_data = 0;

void load_train_data() {
    FILE *fp = fopen(TRAIN_FILE, "r");
    if (fp == NULL) {
        printf("Error: could not open train file.\n");
        exit(1);
    }

    char line[2048];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Email email;
        int is_spam = 0;
        char *token = strtok(line, ",");
        strcpy(email.email, token);
        token = strtok(NULL, ",");
        if (strcmp(token, "spam") == 0) {
            is_spam = 1;
        }
        train_data[num_train_data++] = email;
    }

    fclose(fp);
}

void load_test_data() {
    FILE *fp = fopen(TEST_FILE, "r");
    if (fp == NULL) {
        printf("Error: could not open test file.\n");
        exit(1);
    }

    char line[2048];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Email email;
        strcpy(email.email, line);
        test_data[num_test_data++] = email;
    }

    fclose(fp);
}

int is_spam(const Email *email) {
    int count = 0;
    for (int i = 0; i < num_train_data; i++) {
        if (strcmp(email->email, train_data[i].email) == 0) {
            count++;
        }
    }
    return count > SPAM_THRESHOLD;
}

int main() {
    load_train_data();
    load_test_data();

    for (int i = 0; i < num_test_data; i++) {
        if (is_spam(&test_data[i])) {
            printf("SPAM: %s\n", test_data[i].email);
        } else {
            printf("NOT SPAM: %s\n", test_data[i].email);
        }
    }

    return 0;
}