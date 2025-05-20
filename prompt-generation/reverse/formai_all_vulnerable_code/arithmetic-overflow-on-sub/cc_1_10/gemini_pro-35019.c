//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct{
    char* word;
    int length;
    int errors;
    int startTime;
    int endTime;
} Test;

Test tests[] = {
    {"Lorem ipsum dolor sit amet", 24},
    {"Sed ut perspiciatis unde omnis", 28},
    {"Duis aute irure dolor in reprehenderit", 36},
    {"At vero eos et accusamus et iusto", 29},
    {"Nam libero tempore, cum soluta", 27}
};

char buffer[1024];

int main() {
    int testIndex = 0;
    int totalTime = 0;
    int totalErrors = 0;
    int totalWords = 0;
    Test* currentTest = &tests[testIndex];

    printf("Welcome to the Typing Speed Test!\n");
    printf("Instructions:\n");
    printf("Type the following text as accurately and quickly as possible.\n");
    printf("Press Enter when you are finished.\n");
    printf("\n");

    while (testIndex < 5) {
        currentTest = &tests[testIndex];

        printf("%s\n", currentTest->word);
        currentTest->startTime = time(NULL);
        fgets(buffer, sizeof(buffer), stdin);
        currentTest->endTime = time(NULL);

        currentTest->length = strlen(buffer) - 1;
        currentTest->errors = 0;

        for (int i = 0; i < currentTest->length; i++) {
            if (tolower(buffer[i]) != tolower(currentTest->word[i])) {
                currentTest->errors++;
            }
        }

        totalTime += currentTest->endTime - currentTest->startTime;
        totalErrors += currentTest->errors;
        totalWords += currentTest->length;

        printf("Errors: %d\n", currentTest->errors);
        printf("Time: %d seconds\n", currentTest->endTime - currentTest->startTime);
        printf("Words: %d\n", currentTest->length);
        printf("\n");

        testIndex++;
    }

    printf("Total Errors: %d\n", totalErrors);
    printf("Total Time: %d seconds\n", totalTime);
    printf("Total Words: %d\n", totalWords);

    return 0;
}