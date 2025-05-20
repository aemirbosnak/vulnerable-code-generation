//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORDS 100
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15
#define QOS_THRESHOLD 80

// Function to split a string into words
void split_string(char* str, char** words) {
    int i = 0;
    char* word;
    char* token;

    token = strtok(str, ",.?!;:");
    while (token!= NULL) {
        if (strlen(token) >= MIN_WORD_LENGTH && strlen(token) <= MAX_WORD_LENGTH) {
            words[i] = malloc(strlen(token) + 1);
            strcpy(words[i], token);
            i++;
        }
        token = strtok(NULL, ",.?!;:");
    }
}

// Function to calculate the quality of service (QoS) score
int calculate_qos(char** words) {
    int qos = 0;
    int num_words = 0;
    int avg_word_length = 0;

    // Calculate the number of words and the average word length
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i]!= NULL) {
            num_words++;
            avg_word_length += strlen(words[i]);
        }
    }
    avg_word_length /= num_words;

    // Calculate the QoS score based on the number of words and the average word length
    if (num_words >= 10 && avg_word_length >= 5) {
        qos = QOS_THRESHOLD;
    } else if (num_words >= 5 && avg_word_length >= 7) {
        qos = QOS_THRESHOLD - 5;
    } else if (num_words >= 3 && avg_word_length >= 9) {
        qos = QOS_THRESHOLD - 10;
    } else {
        qos = 0;
    }

    return qos;
}

// Function to print the QoS score
void print_qos(int qos) {
    if (qos == QOS_THRESHOLD) {
        printf("Excellent QoS\n");
    } else if (qos == QOS_THRESHOLD - 5) {
        printf("Good QoS\n");
    } else if (qos == QOS_THRESHOLD - 10) {
        printf("Fair QoS\n");
    } else {
        printf("Poor QoS\n");
    }
}

int main() {
    char input_str[1000];
    char* words[MAX_WORDS];

    printf("Enter a string to analyze:\n");
    scanf("%[^\n]", input_str);

    // Split the input string into words
    split_string(input_str, words);

    // Calculate the QoS score
    int qos = calculate_qos(words);

    // Print the QoS score
    print_qos(qos);

    return 0;
}