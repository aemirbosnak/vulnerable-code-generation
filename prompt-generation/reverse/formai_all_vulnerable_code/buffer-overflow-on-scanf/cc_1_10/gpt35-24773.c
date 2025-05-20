//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include<stdio.h>
#include<string.h>
#define MAX 200

int min(int a,int b,int c){
    if(a<b && a<c){
        return a;
    }else if(b<a && b<c){
        return b;
    }else{
        return c;
    }
}

int levenshteinDistance(char string1[], char string2[], int length1, int length2){
    int costMatrix[length1+1][length2+1];
    int i,j;

    for(i=0; i<=length1; i++){
        for(j=0; j<=length2; j++){
            if(i==0){
                costMatrix[i][j] = j;
            }else if(j==0){
                costMatrix[i][j] = i;
            }else if(string1[i-1] == string2[j-1]){
                costMatrix[i][j] = costMatrix[i-1][j-1];
            }else{
                costMatrix[i][j] = 1 + min(costMatrix[i][j-1], costMatrix[i-1][j], costMatrix[i-1][j-1]);
            }
        }
    }

    return costMatrix[length1][length2];
}

int main(){
    char string1[MAX], string2[MAX];
    int length1,length2,distance;

    printf("Enter String 1: ");
    scanf("%s", string1);

    printf("Enter String 2: ");
    scanf("%s", string2);

    length1 = strlen(string1);
    length2 = strlen(string2);

    distance = levenshteinDistance(string1,string2,length1,length2);

    printf("The Levenshtein Distance between %s and %s is %d.", string1, string2, distance);

    return 0;
}