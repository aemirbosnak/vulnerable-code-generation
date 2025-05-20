//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define PEACEFUL "peaceful"
#define HAPPY "happy"
#define EXCITED "excited"

char* to_upper(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
    return str;
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter a message: ");
    fgets(str, MAX_STR_LEN, stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    char* new_str = malloc(MAX_STR_LEN * sizeof(char));
    strcpy(new_str, str);

    char* ptr = strstr(new_str, "peace");
    if (ptr != NULL) {
        printf("Your message contains the word 'peace'\n");
    }

    if (strstr(new_str, "peaceful") != NULL) {
        printf("Your message is peaceful\n");
        printf("Let's spread peace and love\n");
        char* peaceful_str = to_upper(PEACEFUL);
        strcat(new_str, peaceful_str);
        printf("Your new message: %s\n", new_str);
    }
    else if (strstr(new_str, "happy") != NULL) {
        printf("Your message is happy\n");
        printf("Spread happiness everywhere\n");
        char* happy_str = to_upper(HAPPY);
        strcat(new_str, happy_str);
        printf("Your new message: %s\n", new_str);
    }
    else if (strstr(new_str, "excited") != NULL) {
        printf("Your message is excited\n");
        printf("Let's experience new adventures\n");
        char* excited_str = to_upper(EXCITED);
        strcat(new_str, excited_str);
        printf("Your new message: %s\n", new_str);
    }
    else {
        printf("Your message is neither peaceful, happy nor excited\n");
        printf("Maybe you should try again with a more positive message\n");
    }

    free(new_str);
    return 0;
}