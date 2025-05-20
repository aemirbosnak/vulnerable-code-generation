//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string using recursion
void reverse_string(char *str, int start, int end) {
    char temp;

    if (start >= end) {
        return;
    }

    temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse_string(str, start + 1, end - 1);
}

// Function to check if a given number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to print the prime factors of a given number
void print_prime_factors(int num) {
    for (int i = 2; i <= num; i++) {
        while (num % i == 0) {
            if (is_prime(i)) {
                printf("%d ", i);
                num /= i;
            }
        }
    }
}

// Function to check if a given string is a palindrome
int is_palindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (str[start] != str[end]) {
        return 0;
    }

    return is_palindrome(str, start + 1, end - 1);
}

// Function to reverse a linked list
struct node {
    int data;
    struct node *next;
};

void reverse_linked_list(struct node **head) {
    struct node *current = *head, *prev = NULL;

    while (current != NULL) {
        struct node *next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    *head = prev;
}

// Main function
int main() {
    char str[101];
    int num, len, i, flag;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Check if the string is a palindrome
    flag = is_palindrome(str, 0, len - 1);

    if (flag) {
        printf("The given string is a palindrome.\n");
    } else {
        reverse_string(str, 0, len - 1);
        flag = is_palindrome(str, 0, len - 1);

        if (flag) {
            printf("The reversed string is a palindrome and hence the original string is palindromic.\n");
        } else {
            printf("The given string is not a palindrome.\n");
        }

        // Print the original string
        printf("Original string: %s\n", str);
    }

    printf("Enter a number: ");
    scanf("%d", &num);

    // Print the prime factors of the given number
    print_prime_factors(num);

    // Creating a linked list
    struct node *head = NULL, *second = NULL, *third = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    second = (struct node *)malloc(sizeof(struct node));
    second->data = 2;
    second->next = head;

    third = (struct node *)malloc(sizeof(struct node));
    third->data = 3;
    third->next = second;

    // Reversing the linked list
    reverse_linked_list(&head);

    // Printing the reversed linked list
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}