//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

//function declarations
int min(int a, int b);
int calculate_distance(char *str1, char *str2, int length1, int length2);

int main() {
    //initialize variables
    char str1[MAX_LEN], str2[MAX_LEN];
    int length1, length2, distance;

    //receive input from user
    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);

    //calculate length of input strings
    length1 = strlen(str1)-1;
    length2 = strlen(str2)-1;

    //calculate distance between the strings
    distance = calculate_distance(str1, str2, length1, length2);

    //output result
    printf("Levenshtein Distance between %s and %s is %d", str1, str2, distance);
    return 0;
}

//calculate minimum of two numbers
int min(int a, int b) {
    if(a < b) {
        return a;
    }
    else {
        return b;
    }
}

//calculate Levenshtein Distance between two strings
int calculate_distance(char *str1, char *str2, int length1, int length2) {
    int temp, i, j, cost;
    int distance[length1+1][length2+1];

    //initialize first row and column of matrix
    for(i = 0; i <= length1; i++) {
        distance[i][0] = i;
    }
    for(j = 0; j <= length2; j++) {
        distance[0][j] = j;
    }

    //calculate distance between the strings
    for(i = 1; i <= length1; i++) {
        for(j = 1; j <= length2; j++) {
            if(str1[i-1] == str2[j-1]) {
                cost = 0;
            }
            else {
                cost = 1;
            }
            temp = min(distance[i-1][j] + 1, distance[i][j-1] + 1);
            distance[i][j] = min(temp, distance[i-1][j-1] + cost);
        }
    }

    return distance[length1][length2];
}