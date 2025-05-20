//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
/*
    A program that processes a given text input and counts the frequency 
    of occurrences of each word.

    The program takes input from standard input (stdin) and prints the 
    frequency of each word in ascending order.

    Word is defined as a sequence of characters separated by whitespace.

    Author: Your Name

    To compile: 
        gcc text_processing.c -o text_processing

    To execute:
        ./text_processing < input.txt

    Input:
        The quick brown fox jumped over the lazy dog.

    Output:
        brown 1
        dog 1
        fox 1
        jumped 1
        lazy 1
        over 1
        quick 1
        the 2

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

/* Definition of linked list node for storing frequency count of each word */
typedef struct word_frequency {
    char *word;
    int frequency;
    struct word_frequency *next;
} WordFrequency;

int main() {
    /* Allocate buffer for reading input */
    char *input_buffer = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);

    /* Define head node for linked list */
    WordFrequency *head = NULL;

    while (scanf("%s", input_buffer) == 1) {
        /* Try to find node with same word */
        WordFrequency *curr = head;
        while (curr != NULL) {
            if (strcmp(curr->word, input_buffer) == 0) {
                /* If found, increment frequency count and exit loop */
                curr->frequency++;
                break;
            }
            curr = curr->next;
        }

        /* If node not found, create new node and append to linked list */
        if (curr == NULL) {
            WordFrequency *new_node = (WordFrequency*) malloc(sizeof(WordFrequency));
            new_node->word = (char*) malloc(sizeof(char) * strlen(input_buffer));
            strcpy(new_node->word, input_buffer);
            new_node->frequency = 1;
            new_node->next = NULL;

            /* Append node to end of linked list */
            if (head == NULL) {
                head = new_node;
            } else {
                WordFrequency *tail = head;
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                tail->next = new_node;
            }
        }
    }

    /* Print frequency of each word in ascending order */
    while (head != NULL) {
        /* Find word with smallest frequency count */
        WordFrequency *smallest_node = head;
        WordFrequency *curr = head->next;
        while (curr != NULL) {
            if (curr->frequency < smallest_node->frequency) {
                smallest_node = curr;
            }
            curr = curr->next;
        }

        /* Print word with smallest frequency count */
        printf("%s %d\n", smallest_node->word, smallest_node->frequency);

        /* Delete node from linked list */
        if (smallest_node == head) {
            head = smallest_node->next;
        } else {
            curr = head;
            while (curr->next != smallest_node) {
                curr = curr->next;
            }
            curr->next = smallest_node->next;
        }
        free(smallest_node->word);
        free(smallest_node);
    }

    /* Free input buffer */
    free(input_buffer);

    return 0;
}