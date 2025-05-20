//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//function to read file
void read_file(FILE *fp, char *str) {
    char ch;
    int i = 0;
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            str[i++] = tolower(ch);
        }
    }
    str[i] = '\0';
}

//function to count frequency of words
void count_frequency(char *str, int *freq) {
    int i = 0, j = 0;
    while(str[i]) {
        if(isalpha(str[i])) {
            j = 0;
            while(isalpha(str[i + j])) {
                j++;
            }
            freq[i]++;
            i += j;
        }
        else {
            i++;
        }
    }
}

//function to calculate spam score
int calculate_spam_score(int *freq, int num_words) {
    int score = 0;
    for(int i = 0; i < num_words; i++) {
        if(freq[i] > 2) {
            score += (freq[i] - 2) * (freq[i] - 2);
        }
    }
    return score;
}

int main() {
    FILE *fp;
    char str[10000];
    int freq[26] = {0};
    int num_words = 0;

    //open file for reading
    fp = fopen("spam.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    //read file into string
    read_file(fp, str);

    //count frequency of words
    count_frequency(str, freq);

    //calculate spam score
    int spam_score = calculate_spam_score(freq, num_words);

    //print spam score
    printf("Spam score: %d\n", spam_score);

    return 0;
}