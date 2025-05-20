//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 1024 //maximum length of input
#define MAX_NAME_LENGTH 64 //maximum length of name
#define MAX_EMAIL_LENGTH 64 //maximum length of email address
#define MAX_PHONE_LENGTH 32 //maximum length of phone number
#define MAX_URL_LENGTH 1024 //maximum length of URL

typedef struct input_data {
    char name[MAX_NAME_LENGTH + 1];
    char email[MAX_EMAIL_LENGTH + 1];
    char phone[MAX_PHONE_LENGTH + 1];
    char url[MAX_URL_LENGTH + 1];
} InputData;

void sanitize_input(InputData *data) {
    //sanitize name input
    int name_length = strlen(data->name);
    if (name_length > MAX_NAME_LENGTH) {
        data->name[MAX_NAME_LENGTH] = '\0';
        printf("Name truncated to %d characters.\n", MAX_NAME_LENGTH);
    }

    //sanitize email input
    int email_length = strlen(data->email);
    if (email_length > MAX_EMAIL_LENGTH) {
        data->email[MAX_EMAIL_LENGTH] = '\0';
        printf("Email truncated to %d characters.\n", MAX_EMAIL_LENGTH);
    }

    //sanitize phone input
    int phone_length = strlen(data->phone);
    if (phone_length > MAX_PHONE_LENGTH) {
        data->phone[MAX_PHONE_LENGTH] = '\0';
        printf("Phone number truncated to %d characters.\n", MAX_PHONE_LENGTH);
    }

    //sanitize URL input
    int url_length = strlen(data->url);
    if (url_length > MAX_URL_LENGTH) {
        data->url[MAX_URL_LENGTH] = '\0';
        printf("URL truncated to %d characters.\n", MAX_URL_LENGTH);
    }
}

int main() {
    InputData data;
    printf("Enter your name:\n");
    scanf("%s", data.name);
    printf("Enter your email address:\n");
    scanf("%s", data.email);
    printf("Enter your phone number:\n");
    scanf("%s", data.phone);
    printf("Enter a URL:\n");
    scanf("%s", data.url);

    sanitize_input(&data);

    printf("Name: %s\n", data.name);
    printf("Email: %s\n", data.email);
    printf("Phone: %s\n", data.phone);
    printf("URL: %s\n", data.url);

    return 0;
}