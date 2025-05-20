//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

int passwordlen, i, j, k, l, m, n;
char character[94] = {'!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/',
                      '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
                      '@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
                      'P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_',
                      '`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
                      'p','q','r','s','t','u','v','w','x','y','z','{','|','}','~'};
char password[64];

srand((unsigned int)time(NULL));

printf("Please type password length between 8 and 64: ");
scanf(" %d", &passwordlen);

while(passwordlen < 8 || passwordlen > 64){

    printf("Please type password length between 8 and 64: ");
    scanf(" %d", &passwordlen);
}

for(i = 0; i < passwordlen; i++){

    j = rand() % 93 + 1;
    k = rand() % 93 + 1;
    l = rand() % 93 + 1;
    m = rand() % 93 + 1;
    n = rand() % 93 + 1;

    password[i] = character[j];
    i++;
    password[i] = character[k];
    i++;
    password[i] = character[l];
    i++;
    password[i] = character[m];
    i++;
    password[i] = character[n];
}

password[passwordlen] = '\0';

printf("Your secure password is:\n%s\n", password);

return 0;
}