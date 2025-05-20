//FormAI DATASET v1.0 Category: Image Steganography ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char original[100], secret[20], result[200], temp[20];
    int i, j, k;

    printf("Enter the original message : ");
    fgets(original, 100, stdin);

    printf("Enter the secret message : ");
    scanf("%s", secret);

    // Hide secret message in original message
    for(i=0, j=0, k=0; i<strlen(original); i++, j++){
        if(original[i] == ' ' || original[i] == '\n'){
            temp[j] = original[i];
            j++;
            for(int l=0; l<strlen(secret); l++){
                temp[j] = secret[l];
                j++;
            }
        }
        temp[j] = original[i];
    }

    temp[j] = '\0';

    printf("Resultant message : %s\n", temp);

    // Retrieve the hidden message from the resultant message
    for(i=0, j=0, k=0; i<strlen(temp); i++){
        if(temp[i] == ' ' || temp[i] == '\n'){
            result[k] = '\0';
            if(strcmp(result, secret) == 0){
                printf("\nSecret message found at position : %d\n", j - strlen(secret));
                break;
            }
            j++;
            k=0;
            continue;
        }
        result[k++] = temp[i];
    }

    // If secret message not found
    if(i == strlen(temp)){
        printf("\nSecret message not found!\n");
    }
  
  return 0;
}