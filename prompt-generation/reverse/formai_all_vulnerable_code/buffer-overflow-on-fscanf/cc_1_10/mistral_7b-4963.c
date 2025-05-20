//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 100
#define MIN_NUMBER -2147483648
#define MAX_NUMBER 2147483647

typedef struct{
    int number;
    char name[20];
} NumberNamePair;

void print_number_name_pair(NumberNamePair num_name){
    printf("Number : %d\n", num_name.number);
    printf("Name   : %s\n", num_name.name);
}

int calculate_sum_of_digits(int number){
    int sum = 0;
    int digit;

    while(number != 0){
        digit = number % 10;
        sum += digit;
        number /= 10;
    }

    return sum;
}

int check_if_number_is_palindrome(int number){
    int reverse_number = 0;
    int original_number = number;

    while(number != 0){
        int digit = number % 10;
        reverse_number = reverse_number * 10 + digit;
        number /= 10;
    }

    return reverse_number == original_number;
}

int main(int argc, char *argv[])
{
    int i, j, sum, palindrome_count = 0;
    NumberNamePair numbers[MAX_DIGITS];

    if(argc != 2){
        printf("Usage : %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL){
        perror("Error opening file");
        return 1;
    }

    while(fscanf(fp, "%d%s", &numbers[i].number, numbers[i].name) != EOF){
        sum = calculate_sum_of_digits(numbers[i].number);

        if(check_if_number_is_palindrome(sum)){
            palindrome_count++;
        }

        i++;
    }

    fclose(fp);

    printf("Total number of numbers read from file : %d\n", i);
    printf("Total number of palindrome sums : %d\n", palindrome_count);

    for(i = 0; i < palindrome_count; i++){
        printf("\nPalindrome Sum : %d\n", sum);
        print_number_name_pair(numbers[i]);
    }

    return 0;
}