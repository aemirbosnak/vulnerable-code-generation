//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

//Declaring Function Prototype
int levenshtein_distance(char *, char *);

int main(){

    char word1[100], word2[100];
    printf("Please Enter the first word \n");
    scanf("%s",word1);
    printf("Please Enter the second word \n");
    scanf("%s",word2);
    printf("\nElementary, my Dear Watson. Levenshtein Distance between \"%s\" and \"%s\" is : %d\n", word1, word2, levenshtein_distance(word1, word2));
    return 0;
}

//Function Definition
int levenshtein_distance(char *word1, char *word2){

    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int i,j;
    //Declaring a 2D array of size (len1+1)x(len2+1)
    int arr[len1+1][len2+1];

    //Initializing the array
    for(i=0;i<=len1;i++){
        for(j=0;j<=len2;j++){
            if(i==0) arr[i][j]=j;
            else if(j==0) arr[i][j]=i;
            else arr[i][j]=0;
        }
    }

    //Calculating the Levenshtein Distance
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(word1[i-1]==word2[j-1]){
                arr[i][j]=arr[i-1][j-1];
            }
            else{
                arr[i][j]=1+minimum(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
            }
        }
    }

    //Final Resultant Array
    int res=arr[len1][len2];
    return res;
}

//Function that Returns the minimum of 3 Numbers
int minimum(int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}