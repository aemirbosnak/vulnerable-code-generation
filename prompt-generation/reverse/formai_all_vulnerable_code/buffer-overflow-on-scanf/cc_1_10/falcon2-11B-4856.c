//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char name[100], title[100], company[100], address[100], city[100], state[100], zip[100], phone[100], email[100];
    char skills[100][100];

    printf("Welcome to the Romantic Resume Parsing System!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);

    printf("Please enter your title:\n");
    scanf("%s", title);
    printf("Title: %s\n", title);

    printf("Please enter your company:\n");
    scanf("%s", company);
    printf("Company: %s\n", company);

    printf("Please enter your address:\n");
    scanf("%s", address);
    printf("Address: %s\n", address);

    printf("Please enter your city:\n");
    scanf("%s", city);
    printf("City: %s\n", city);

    printf("Please enter your state:\n");
    scanf("%s", state);
    printf("State: %s\n", state);

    printf("Please enter your zip code:\n");
    scanf("%s", zip);
    printf("Zip Code: %s\n", zip);

    printf("Please enter your phone number:\n");
    scanf("%s", phone);
    printf("Phone Number: %s\n", phone);

    printf("Please enter your email address:\n");
    scanf("%s", email);
    printf("Email Address: %s\n", email);

    printf("Please enter your skills (one per line):\n");
    for (int i = 0; i < 100; i++) {
        scanf("%s", skills[i]);
    }

    printf("Resume Parsing Complete!\n");

    return 0;
}