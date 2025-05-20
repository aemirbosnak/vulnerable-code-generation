//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct pixel {
    int x,y;
    char c;
};

void draw(struct pixel *p,int n) {
    for(int i=0;i<n;i++) {
        printf("%c",p[i].c);
    }
}

int main() {
    char input[1000];
    int len,i,j,k;

    printf("Enter some text: ");
    scanf("%s",input);
    len=strlen(input);

    struct pixel p[len];

    for(i=0;i<len;i++) {
        p[i].c=input[i];
        p[i].x=i;
        p[i].y=0;
    }

    for(i=0;i<len;i++) {
        for(j=0;j<len;j++) {
            if(i==j) {
                p[i].y=0;
            } else if(i<j) {
                p[i].y=p[j].y+1;
            } else {
                p[i].y=p[j].y-1;
            }
        }
    }

    for(i=0;i<len;i++) {
        printf("\n");
        for(j=i-1;j>=0;j--) {
            printf(" ");
        }
        draw(p,len);
    }

    return 0;
}