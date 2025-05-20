//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(){

char str[1000];
int len;

printf("Enter a string: ");
scanf("%s",str);

len=strlen(str);

printf("\nThe original string is:\n%s\n",str);

printf("\nThe length of the string is: %d\n",len);

printf("\nThe reverse of the string is:\n");

for(int i=len-1;i>=0;i--){
    printf("%c",str[i]);
}

printf("\n\n");

int vowel_count=0;

for(int i=0;i<len;i++){

    if(isalpha(str[i])){

        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){

            vowel_count++;

        }

    }

}

printf("\nThe number of vowels in the string is: %d\n",vowel_count);

printf("\nThe string in uppercase is:\n");

for(int i=0;i<len;i++){
    printf("%c",toupper(str[i]));
}

printf("\n\n");

int word_count=0;

char *token;

token=strtok(str," ");

while(token!=NULL){

    printf("\nThe word is: %s\n",token);

    word_count++;

    token=strtok(NULL," ");

}

printf("\nThe number of words in the string is: %d\n",word_count);

return 0;
}