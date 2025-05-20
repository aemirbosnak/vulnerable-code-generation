//FormAI DATASET v1.0 Category: Text processing ; Style: paranoid
#include<stdio.h>
#include<string.h>

int main(){
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // Check for Capital Letters which are not in the beginning of the sentence
    for(int i=1; i<strlen(sentence); i++){
        if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
            printf("Warning: Capital letter found at position %d\n", i+1);

            // Replace the capital letter with a random lowercase letter 
            int random_num = (int)((rand() % 26) + 97);
            sentence[i] = (char)random_num;
            printf("Replaced with %c\n", sentence[i]);
        }
    }

    // Check for unwanted characters
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] == '$' || sentence[i] == '%' || sentence[i] == '&' || sentence[i] == '#'){
            printf("Error: Unwanted character found at position %d\n", i+1);
            printf("Replacing with * \n");
            sentence[i] = '*';
        }
    }

    // Check for phone numbers
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] >= '0' && sentence[i] <= '9'){
            if(sentence[i+1] >= '0' && sentence[i+1] <= '9'){
                if(sentence[i+2] >= '0' && sentence[i+2] <= '9'){
                    if(sentence[i+3] == '-' && sentence[i+4] >= '0' && sentence[i+4] <= '9' && 
                    sentence[i+5] >= '0' && sentence[i+5] <= '9' && sentence[i+6] >= '0' && sentence[i+6] <= '9'){
                        printf("Warning: Phone number found at position %d\n", i+1);
                        printf("Replacing with ****-****\n");
                        sentence[i] = '*';
                        sentence[i+1] = '*';
                        sentence[i+2] = '*';
                        sentence[i+3] = '-';
                        sentence[i+4] = '*';
                        sentence[i+5] = '*';
                        sentence[i+6] = '*';
                    }
                }
            }
        }
    }

    // Check for email addresses
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] == '@'){
            int j=i-1,k=i+1;
            while(sentence[j] != ' ' && j >= 0){
                j--;
            }
            while(sentence[k] != ' ' && k < strlen(sentence)){
                k++;
            }
            printf("Warning: Email address found at position %d\n", j+2);
            printf("Replacing with *********\n");
            for(int p=j+2; p<k; p++){
                sentence[p] = '*';
            }
        }
    }

    printf("The processed sentence: %s\n", sentence);
    return 0;
}