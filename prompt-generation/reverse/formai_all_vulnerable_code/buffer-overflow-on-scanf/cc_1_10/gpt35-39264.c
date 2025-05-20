//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//structure for passing data to threads
struct threadData{
    char *str;
    int start;
    int end;
};

//function to check if a string is palindrome
int checkPalindrome(char *str, int start, int end){
    while(start < end){
        if(str[start] != str[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

//thread function to check palindrome
void *threadChecker(void *arg){
    struct threadData *data = (struct threadData *) arg;
    char *str = data->str;
    int start = data->start;
    int end = data->end;
    int isPalindrome = checkPalindrome(str, start, end);

    //print result
    if(isPalindrome){
        printf("%.*s is a Palindrome.\n", end-start+1, str+start);
    }else{
        printf("%.*s is not a Palindrome.\n", end-start+1, str+start);
    }
    return NULL;
}

int main(){
    //input string
    char str[100];
    printf("Enter a String to check Palindrome: ");
    scanf("%s", str);
    int len = strlen(str);

    //creating threads
    pthread_t threads[len];
    struct threadData data[len];
    for(int i=0; i<len; i++){
        data[i].str = str;
        data[i].start = i;
        data[i].end = len-1;
        pthread_create(&threads[i], NULL, threadChecker, (void*)&data[i]);
    }

    //joining threads
    for(int i=0; i<len; i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}