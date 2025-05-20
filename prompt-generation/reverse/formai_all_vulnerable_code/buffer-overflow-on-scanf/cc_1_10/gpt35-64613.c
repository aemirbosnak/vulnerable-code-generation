//FormAI DATASET v1.0 Category: Error handling ; Style: Ada Lovelace
/* === Ada Lovelace Style C Error Handling Example === */

// Libraries and Headers
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

// Function to handle errors
void error_handler(int error_code){
    switch(error_code){
        case 1:
            printf("Error: Invalid input.\n");
            break;
        case 2:
            printf("Error: Could not open file.\n");
            break;
        default:
            printf("Unknown Error.\n");
    }
}

// Main function
int main(){
    // Variables
    FILE *fp;
    char filename[20];
    int num, dividend, divisor, result;

    // Get filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    if((fp = fopen(filename, "r")) == NULL){
        error_handler(2);
        exit(EXIT_FAILURE);
    }

    // Get dividend and divisor
    printf("Enter dividend: ");
    if(scanf("%d", &dividend)!=1){
        error_handler(1);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    printf("Enter divisor: ");
    if(scanf("%d", &divisor) != 1){
        error_handler(1);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Perform division
    if(divisor == 0){
        error_handler(1);
        fclose(fp);
        exit(EXIT_FAILURE);
    }else{
        result = dividend/divisor;
        printf("%d / %d = %d\n", dividend, divisor, result);
    }

    // Close file
    fclose(fp);

    return 0;
}