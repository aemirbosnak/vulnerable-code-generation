//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Structure to hold words and their frequencies
struct wordfreq{
    char word[50];
    int freq;
};
typedef struct wordfreq WORDFREQ;

// Function to remove punctuations from a string
void removePunctuations(char* str){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(ispunct(str[i])){
            for(int j=i; j<len; j++){
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
}

// Function to convert a string to lowercase
void toLowerCase(char* str){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        str[i] = tolower(str[i]);
    }
}

// Function to compare two words
int compare(const void* a, const void* b){
    WORDFREQ* x = (WORDFREQ*)a;
    WORDFREQ* y = (WORDFREQ*)b;

    return strcmp(x->word, y->word);
}

// Function to print top 10 frequent words
void printTop10(WORDFREQ* wf, int n){
    qsort(wf, n, sizeof(WORDFREQ), compare);

    printf("\nTop 10 most frequent words:\n");
    for(int i=0; i<10; i++){
        printf("%s\t\t%d\n", wf[n-i-1].word, wf[n-i-1].freq);
    }
}

int main(){
    FILE* fp;
    char filename[50];
    char word[50];
    int count = 0, n = 0;

    // Ask for input file name
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    // Read the input file
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file %s!", filename);
        exit(1);
    }

    // Count the number of words in the file
    while(fscanf(fp, "%s", word) != EOF){
        removePunctuations(word);
        toLowerCase(word);
        count++;
    }

    // Allocate memory for the word frequency list
    WORDFREQ* wf = (WORDFREQ*)malloc(count*sizeof(WORDFREQ));

    // Read the input file again to populate the word frequency list
    fseek(fp, 0, SEEK_SET);
    while(fscanf(fp, "%s", word) != EOF){
        removePunctuations(word);
        toLowerCase(word);

        int found = 0;
        for(int i=0; i<n; i++){
            if(strcmp(word, wf[i].word) == 0){
                wf[i].freq++;
                found = 1;
                break;
            }
        }

        if(!found){
            strcpy(wf[n].word, word);
            wf[n].freq = 1;
            n++;
        }
    }

    // Print the top 10 frequent words
    printTop10(wf, n);

    // Cleanup
    fclose(fp);
    free(wf);

    return 0;
}