//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<math.h>

#define MAX_SIZE 10000
#define MAX_KEY_SIZE 100
#define ALPHABET_SIZE 26

struct Key{
    char key[MAX_KEY_SIZE];
    int key_size;
};

struct Key generate_key(int key_size){
    struct Key key;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int i;

    for(i=0;i<key_size;i++){
        key.key[i] = alphabet[rand()%26];
    }
    key.key_size = key_size;

    return key;
}

void encrypt(char *text, struct Key key){
    int i,j,n,k;
    char encrypted_text[MAX_SIZE];

    n = strlen(text);
    for(i=0;i<n;i++){
        if(isalpha(text[i])){
            if(isupper(text[i])){
                text[i] = tolower(text[i]);
            }

            j = tolower(text[i]) - 'a';
            k = (j + key.key[i%key.key_size] - 'a') % 26;
            text[i] = k + 'a';
        }
    }
}

int main(){
    char text[MAX_SIZE];
    struct Key key;

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    printf("Enter the key size: ");
    scanf("%d", &key.key_size);

    key = generate_key(key.key_size);

    encrypt(text, key);

    printf("Encrypted text: %s\n", text);

    return 0;
}