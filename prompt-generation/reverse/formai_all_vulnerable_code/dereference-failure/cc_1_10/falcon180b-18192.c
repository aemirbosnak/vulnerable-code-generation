//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

void reverseString(char* str);
void reverseWords(char* sentence);

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    reverseWords(sentence);

    printf("Reversed sentence: %s\n", sentence);

    return 0;
}

void reverseString(char* str)
{
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char* sentence)
{
    char* start = sentence;
    char* end = sentence + strlen(sentence) - 1;

    while (isspace(*end)) {
        end--;
    }

    while (start < end) {
        char* wordStart = start;
        while (!isspace(*(end - 1))) {
            end--;
        }
        char* wordEnd = end;

        while (wordStart < wordEnd) {
            char temp = *wordStart;
            *wordStart = *wordEnd;
            *wordEnd = temp;
            wordStart++;
            wordEnd--;
        }
        start = wordEnd + 1;
    }
}