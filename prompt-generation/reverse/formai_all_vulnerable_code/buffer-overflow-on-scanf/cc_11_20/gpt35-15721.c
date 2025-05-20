//FormAI DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>

int main() {

int n,i,j,k,l;

printf("Enter a number between 2 and 26: ");

scanf("%d", &n);

if(n<=1 || n>26){

printf("Invalid Input, Please enter a number between 2 and 26.");

return 0;

}

else{

for(i=1;i<=n;i++){

for(j=n-1;j>=i;j--){

printf(" ");

}

for(k=1;k<=i;k++){

printf("%c", k+96);

}

for(l=i-1;l>=1;l--){

printf("%c", l+96);

}

printf("\n");

}

for(i=n-1;i>=1;i--){

for(j=n-1;j>=i;j--){

printf(" ");

}

for(k=1;k<=i;k++){

printf("%c", k+96);

}

for(l=i-1;l>=1;l--){

printf("%c", l+96);

}

printf("\n");

}

}

printf("You and Me, we'll always be one, just like the pattern printed by this code.\n");

return 0;
}