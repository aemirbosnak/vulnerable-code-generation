//FormAI DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include<stdio.h>
#include<string.h>

int main(){
    char email[100];
    printf("Enter an email: ");
    scanf("%s", email);
    
    // Check for spam keywords
    char spam_keywords[5][20] = {"free", "money", "lottery", "viagra", "sex"};
    int i, flag = 0;
    for(i = 0; i < 5; i++){
        if(strstr(email, spam_keywords[i]) != NULL){
            flag = 1;
            break;
        }
    }
    
    // Check for excessive use of exclamation marks and question marks
    int exclamation_count = 0, question_count = 0;
    int len = strlen(email);
    for(i = 0; i < len; i++){
        if(email[i] == '!'){
            exclamation_count++;
        }
        else if(email[i] == '?'){
            question_count++;
        }
    }
    
    // Check if the email is from a known spam domain
    char known_domains[10][20] = {"spamdomain.com", "spammydomain.net", "junkmail.org"};
    char *domain = strtok(email, "@");
    domain = strtok(NULL, "@");
    int domain_flag = 0;
    for(i = 0; i < 10; i++){
        if(strcmp(domain, known_domains[i]) == 0){
            domain_flag = 1;
            break;
        }
    }
    
    // Determine if the email is spam or not
    if(flag || exclamation_count > 3 || question_count > 2 || domain_flag){
        printf("The email is likely spam.\n");
    }
    else{
        printf("The email is likely not spam.\n");
    }
    
    return 0;
}