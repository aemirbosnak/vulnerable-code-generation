//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the summary of a text
void summarize(char* text) {
    char* summary = (char*)malloc(100);
    int i, j, k;
    int n = strlen(text);
    int count[26] = {0};
    
    // Counting the frequency of each character in the text
    for (i = 0; i < n; i++) {
        count[text[i] - 'a']++;
    }
    
    // Sorting the characters in decreasing order of frequency
    for (i = 0; i < 26; i++) {
        for (j = i + 1; j < 26; j++) {
            if (count[i] < count[j]) {
                char temp = count[i];
                count[i] = count[j];
                count[j] = temp;
                char temp2 = text[i];
                text[i] = text[j];
                text[j] = temp2;
            }
        }
    }
    
    // Printing the summary
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 26; j++) {
            if (count[j] > 0) {
                if (i < 100) {
                    summary[i] = text[j];
                    count[j]--;
                    i++;
                }
            }
        }
    }
    summary[i] = '\0';
    
    // Printing the summary
    printf("Summary: %s\n", summary);
}

// Driver code
int main() {
    char text[100];
    printf("Enter the text: ");
    scanf("%s", text);
    summarize(text);
    return 0;
}