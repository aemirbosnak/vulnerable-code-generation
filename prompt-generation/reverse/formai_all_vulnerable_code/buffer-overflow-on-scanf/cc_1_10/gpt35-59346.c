//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int levensteinDistance(char *str1, char *str2) { //custom function for calculating the Lev Distance
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1+1][len2+1]; //declare the matrix for dynamic processing
    int i,j;

    for(i=0;i<=len1;i++) {
        matrix[i][0]=i;
    }

    for(i=0;i<=len2;i++) {
        matrix[0][i]=i;
    }

    for(i=1;i<=len1;i++) {  
        for(j=1;j<=len2;j++) {
            int cost;
            if(str1[i-1]==str2[j-1]) {
                cost = 0; //no cost for matching characters
            } else {
                cost = 1; //cost of 1 for mismatched characters
            }
            //fill in the matrix
            int deletion = matrix[i-1][j] + 1;
            int insertion = matrix[i][j-1] + 1;
            int substitution = matrix[i-1][j-1] + cost;
            matrix[i][j] = deletion < insertion ? deletion : insertion;
            matrix[i][j] = substitution < matrix[i][j] ? substitution : matrix[i][j];
        }
    }
    return matrix[len1][len2];
}

int main() {
    printf("Welcome to the surreal Lev Distance Calculator!\n");
    printf("Please enter the first surreal string: ");
    char str1[100];
    scanf("%s", str1);
    printf("Good, and now the second surreal string: ");
    char str2[100];
    scanf("%s", str2);
    system("cls"); //clear the screen in a surreal way
    printf("Processing..\n");
    int levDistance = levensteinDistance(str1,str2);
    printf("The surreal Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, levDistance);
    printf("Thank you for using the surreal Lev Distance Calculator!\n\n");
    return 0; //end program in a surreal way
}