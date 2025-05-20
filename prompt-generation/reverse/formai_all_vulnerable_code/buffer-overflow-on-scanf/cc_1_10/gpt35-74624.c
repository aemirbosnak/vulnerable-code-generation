//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include<stdio.h>
#include<string.h>

//Function to find minimum of three integers
int minimum(int a, int b, int c){
    int min = a;
    if(b<min){
        min = b;
    }
    if(c<min){
        min = c;
    }
    return min;
}

int levenshtein_distance(char* str1, char* str2){
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int matrix[length1+1][length2+1];

    //Fill the matrix with 0
    for(int i=0; i<=length1; i++){
        for(int j=0; j<=length2; j++){
            matrix[i][j] = 0;
        }
    }

    //Fill the first row and first column
    for(int i=0; i<=length1; i++){
        matrix[i][0] = i;
    }
    for(int j=0; j<=length2; j++){
        matrix[0][j] = j;
    }

    //Fill rest of the matrix
    for(int i=1; i<=length1; i++){
        for(int j=1; j<=length2; j++){
            int deletion = matrix[i-1][j] + 1;
            int insertion = matrix[i][j-1] + 1;
            int substitution = matrix[i-1][j-1];
            if(str1[i-1] != str2[j-1]){
                substitution += 1;
            }
            matrix[i][j] = minimum(deletion, insertion, substitution);
        }
    }

    return matrix[length1][length2];
}

//Main function to test the above code
int main(){
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between the strings \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}