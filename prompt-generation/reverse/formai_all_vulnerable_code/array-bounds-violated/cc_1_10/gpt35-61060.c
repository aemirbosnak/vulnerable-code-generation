//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_STRING_LENGTH 1000
#define MAX_WORD_LENGTH 50

// structure to hold word and its frequency
struct word {
    char str[MAX_WORD_LENGTH];
    int freq;
};

// function to remove unwanted characters from string
void clean_string(char *s) {
    int i,j;
    for(i=0,j=0;s[i];i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[j++] = s[i] + 32;   //convert to lowercase
        }
        else if(s[i] >= 'a' && s[i] <= 'z') {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

// function to check if word is already present in array of words
bool is_word_present(struct word arr[], int n, char str[]) {
    int i;
    for(i=0;i<n;i++) {
        if(!strcmp(arr[i].str, str))
            return true;
    }
    return false;
}

// function to add word to array of words and update frequency
void add_word(struct word arr[], int *n, char str[]) {
    strcpy(arr[*n].str, str);
    arr[*n].freq = 1;
    (*n)++;
}

// function to increment frequency of existing word in array
void increment_freq(struct word arr[], int n, char str[]) {
    int i;
    for(i=0;i<n;i++) {
        if(!strcmp(arr[i].str, str)) {
            arr[i].freq++;
            break;
        }
    }
}

int main() {
    // declare variables
    char input_string[MAX_STRING_LENGTH];
    struct word word_arr[MAX_STRING_LENGTH/MAX_WORD_LENGTH];
    int i,n=0,j,k,len;
    bool word_present;

    // get input string from user
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    len = strlen(input_string);

    if(input_string[len-1] == '\n')
        input_string[len-1] = '\0';    // remove newline character from input string

    // remove unwanted characters from input string and convert to lowercase
    clean_string(input_string);

    // break input string into words and count frequency of each word
    i=0;
    while(input_string[i] != '\0') {
        j=i;
        while(input_string[i] != ' ' && input_string[i] != '\0')
            i++;

        if(input_string[i] == ' ')
            input_string[i++] = '\0';

        word_present = is_word_present(word_arr, n, input_string+j);
        if(word_present)
            increment_freq(word_arr, n, input_string+j);
        else
            add_word(word_arr, &n, input_string+j);
    }

    // display word frequency
    printf("\nWord frequency in the entered string:\n");
    for(i=0;i<n;i++)
        printf("%s - %d\n", word_arr[i].str, word_arr[i].freq);

    return 0;
}