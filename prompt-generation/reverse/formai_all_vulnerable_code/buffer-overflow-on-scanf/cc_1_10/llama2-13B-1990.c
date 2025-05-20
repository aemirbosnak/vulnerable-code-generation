//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the comparison function
int compare(const void *a, const void *b) {
    // Use the user-defined comparison function
    int result = strcmp((const char *)a, (const char *)b);
    return result;
}

int main() {
    // Define the array of strings to sort
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "lazy", "dog"};
    int numWords = sizeof(words) / sizeof(words[0]);

    // Define the sorting options
    int option = 0;
    while (option < 4) {
        printf("Select a sorting option (1-4): ");
        scanf("%d", &option);

        // Switch on the sorting option
        switch (option) {
            case 1:
                // Sort in ascending order
                qsort(words, numWords, sizeof(words[0]), compare);
                break;
            case 2:
                // Sort in descending order
                qsort(words, numWords, sizeof(words[0]), compare);
                break;
            case 3:
                // Sort in random order
                qsort(words, numWords, sizeof(words[0]), (int (*)(const void *, const void *))rand());
                break;
            case 4:
                // Sort in reverse order
                qsort(words, numWords, sizeof(words[0]), (int (*)(const void *, const void *))-1);
                break;
        }
    }

    // Print the sorted array of words
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}