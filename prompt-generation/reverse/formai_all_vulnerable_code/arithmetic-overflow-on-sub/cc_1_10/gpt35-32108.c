//FormAI DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of lines you want to print: ");
    scanf("%d", &n); // take input from user

    // variables to keep track of pattern
    int count = 1;
    int space_count = n-1; 

    // loop to print the pattern
    for(int i=1; i<=n; i++){
        // print spaces
        for(int j=1; j<=space_count; j++){
            printf("  ");
        }

        // print numbers
        for(int j=1; j<=count; j++){
            printf("%d ", j);
        }

        // print spaces
        for(int j=1; j<=space_count; j++){
            printf("  ");
        }

        // update variables
        count += 2;
        space_count--;

        // move to new line
        printf("\n");
    }

    // variables to keep track of pattern
    count -= 4;
    space_count = 1;

    // loop to print the pattern in reverse
    for(int i=1; i<=n-1; i++){
        // print spaces
        for(int j=1; j<=space_count; j++){
            printf("  ");
        }

        // print numbers
        for(int j=1; j<=count; j++){
            printf("%d ", j);
        }

        // print spaces
        for(int j=1; j<=space_count; j++){
            printf("  ");
        }

        // update variables
        count -= 2;
        space_count++;

        // move to new line
        printf("\n");
    }

    return 0;
}