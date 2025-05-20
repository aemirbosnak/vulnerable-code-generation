//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include<stdio.h>
#include<string.h>

int main(){
    char str[100], copy[100];
    int length, choice, i, j, k, flag;

    printf("Hey! I'm a mischievous string manipulator. Enter your favourite phrase: ");
    fgets(str, 100, stdin);
    length = strlen(str)-1;

    while(1){
        printf("\nWhat do you want me to do with this string?\n");
        printf("1. Reverse the string\n2. Remove vowels\n3. Find and replace a substring\n4. Count number of characters\n5. Copy the string\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //to consume the newline character left by scanf
    
        switch(choice){
            case 1:
                for(i=length-1; i>=0; i--){
                    printf("%c", str[i]);
                }
                break;

            case 2:
                printf("Your phrase without vowels: ");
                for(i=0; i<length; i++){
                    flag = 0;
                    switch(str[i]){
                        case 'a': case 'e': case 'i': case 'o': case 'u':
                        case 'A': case 'E': case 'I': case 'O': case 'U':
                            flag = 1;
                            break;
                    }
                    if(flag == 0){
                        printf("%c", str[i]);
                    }
                }
                break;

            case 3:
                printf("Enter the substring to find: ");
                char find[20], replace[20];
                fgets(find, 20, stdin);
                printf("Enter the substring to replace: ");
                fgets(replace, 20, stdin);
                int findlen = strlen(find)-1; //-1 to remove newline character
                int replacelen = strlen(replace)-1;
                
                printf("Your phrase with replaced substring: ");
                for(i=0; i<length; i++){
                    if(str[i] == find[0]){
                        flag = 1;
                        for(j=0; j<findlen; j++){
                            if(str[i+j] != find[j]){
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1){
                            for(k=0; k<replacelen; k++){
                                printf("%c", replace[k]);
                            }
                            i += findlen-1;
                        }
                        else{
                            printf("%c", str[i]);
                        }
                    }
                    else{
                        printf("%c", str[i]);
                    }
                }
                break;

            case 4:
                printf("Your phrase has %d characters (including spaces and punctuation).\n", length);
                break;

            case 5:
                printf("Your phrase has been copied with love ❤️\n");
                strcpy(copy, str);
                printf("Copied phrase: %s", copy);
                break;

            case 6:
                printf("Aw, do you want me to go? Fine then. Bye bye! 👋🏼\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}