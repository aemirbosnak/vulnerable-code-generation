//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024
#define MAX_NUM_KEYWORDS 100
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int isEnabled;
} Keyword;

int main() {
    int numKeywords = 0;
    Keyword keywords[MAX_NUM_KEYWORDS];
    char input[MAX_STRING_LENGTH];
    char keyword[MAX_KEYWORD_LENGTH];
    int isKeywordEnabled = 0;
    int i, j;

    // Prompt the user to enter the number of keywords to monitor
    printf("Enter the number of keywords to monitor: ");
    scanf("%d", &numKeywords);

    // Prompt the user to enter the keywords to monitor
    printf("Enter the keywords to monitor:\n");
    for (i = 0; i < numKeywords; i++) {
        scanf("%s", keywords[i].keyword);
        keywords[i].isEnabled = 1;
    }

    // Prompt the user to enter the text to scan
    printf("Enter the text to scan:\n");
    fgets(input, MAX_STRING_LENGTH, stdin);

    // Convert the input text to lowercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Check for each keyword in the input text
    for (i = 0; i < numKeywords; i++) {
        if (keywords[i].isEnabled) {
            strcpy(keyword, keywords[i].keyword);
            isKeywordEnabled = 1;
            for (j = 0; j < strlen(input); j++) {
                if (strstr(input, keyword)!= NULL) {
                    printf("Keyword \"%s\" found in the text.\n", keyword);
                    break;
                }
            }
        }
    }

    if (!isKeywordEnabled) {
        printf("No enabled keywords found in the text.\n");
    }

    return 0;
}