//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct key{
    char letter;
    int code;
}key_table[26];              //structure to hold the key table

char msg[100],enc_msg[100],dec_msg[100],key[26],cipher[26];   //message, encrypted message, decrypted message, key and cipher array

void generate_key(){       //function to generate random key
    int i,j,len;
    char* alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    len = strlen(alpha);
    srand(time(NULL));
    for(i=0;i<len;i++)
        key[i] = alpha[rand()%len];
    key[len] = '\0';
}

void init_key_table(){     //function to initialize the key table
    int i;
    for(i=0;i<26;i++){
        key_table[i].letter = (char)(i+'A');
        key_table[i].code = i;
    }
}

void display_key_table(){     //function to display the key table
    int i;
    printf("\n--- KEY TABLE ---\n");
    for(i=0;i<26;i++)
        printf("%c -> %d\n",key_table[i].letter,key_table[i].code);
}

void create_cipher(){     //function to create a cipher using given key
    int i,j,len;
    len = strlen(key);
    for(i=0;i<len;i++){
        for(j=0;j<26;j++){
            if(key_table[j].letter == key[i]){
                cipher[i] = (char)(j+'A');
                break;
            }
        }
    }
    cipher[len] = '\0';
}

void display_cipher(){    //function to display the cipher
    printf("\nCipher : %s\n",cipher);
}

void encrypt(){       //function to encrypt the message using the cipher
    int i,j,len;
    len = strlen(msg);
    for(i=0;i<len;i++){
        if(msg[i] == ' ')
            enc_msg[i] = ' ';
        else{
            for(j=0;j<26;j++){
                if(key_table[j].letter == msg[i]){
                    enc_msg[i] = cipher[j];
                    break;
                }
            }
        }
    }
    enc_msg[len] = '\0';
}

void display_enc_msg(){    //function to display the encrypted message
    printf("\nEncrypted Message : %s\n",enc_msg);
}

void decrypt(){        //function to decrypt the message using the cipher
    int i,j,len;
    len = strlen(enc_msg);
    for(i=0;i<len;i++){
        if(enc_msg[i] == ' ')
            dec_msg[i] = ' ';
        else{
            for(j=0;j<26;j++){
                if(cipher[j] == enc_msg[i]){
                    dec_msg[i] = key_table[j].letter;
                    break;
                }
            }
        }
    }
    dec_msg[len] = '\0';
}

void display_dec_msg(){    //function to display the decrypted message
    printf("\nDecrypted Message : %s\n\n",dec_msg);
}

int main(){
    printf("\n*** Simple Substitution Cipher ***\n\n");
    printf("Enter the message to encrypt : ");
    gets(msg);
    generate_key();
    printf("\nGenerated Key : %s\n",key);
    init_key_table();
    display_key_table();
    create_cipher();
    display_cipher();
    encrypt();
    display_enc_msg();
    decrypt();
    display_dec_msg();
    return 0;
}