//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

int levenshtein(char *str1, char *str2);

int main(){
    char input1[100];
    char input2[100];
    printf("Solve the mystery of the Levenshtein Distance\n\n");
    printf("Enter the first word or phrase: ");
    scanf("%s", input1);
    printf("Enter the second word or phrase: ");
    scanf("%s", input2);
    
    int result = levenshtein(input1,input2);
    
    if(result == 0){
        printf("\nThese two words match perfectly!\n");
    } else {
        printf("\nThe Levenshtein Distance between '%s' and '%s' is %d\n", input1, input2, result);
    }
    
    return 0;
}

int levenshtein(char *str1, char *str2){
    int i,j,k;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1+1][len2+1];
    
    // initialization
    for(i=0;i<=len1;i++){
        matrix[i][0]=i;
    }
    for(j=0;j<=len2;j++){
        matrix[0][j]=j;
    }
    
    // dynamic programming
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1]){
                k=0;
            } else {
                k=1;
            }
            matrix[i][j]=min(matrix[i-1][j]+1,
                             matrix[i][j-1]+1,
                             matrix[i-1][j-1]+k);
        }
    }
    
    return matrix[len1][len2];
}

int min(int x, int y, int z){
    int m=x;
    if(y<m){
        m=y;
    }
    if(z<m){
        m=z;
    }
    return m;
}