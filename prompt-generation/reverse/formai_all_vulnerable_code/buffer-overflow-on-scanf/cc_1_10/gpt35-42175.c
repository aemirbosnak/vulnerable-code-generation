//FormAI DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to encrypt the file
void encryptFile(char *fileName){
    FILE *fpRead,*fpWrite;
    fpRead = fopen(fileName,"rb");
    fpWrite = fopen("encrypted.txt","wb");
    if(fpRead == NULL){
        printf("Unable to open file.");
        return;
    }
    unsigned char key[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                        '0','1','2','3','4','5','6','7','8','9',',','.','?','!',' '};
    unsigned char ch;
    int i=0;
    while(!feof(fpRead)){
        ch = fgetc(fpRead);
        if(ch != EOF){
            ch = ch ^ key[i%64];
            fwrite(&ch,sizeof(ch),1,fpWrite);
            i++;
        }
    }
    printf("File encrypted successfully!\n");
    fclose(fpRead);
    fclose(fpWrite);
}

//Function to decrypt the file
void decryptFile(char *fileName){
    FILE *fpRead,*fpWrite;
    fpRead = fopen(fileName,"rb");
    fpWrite = fopen("decrypted.txt","wb");
    if(fpRead == NULL){
        printf("Unable to open file.\n");
        return;
    }
    unsigned char key[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                        '0','1','2','3','4','5','6','7','8','9',',','.','?','!',' '};
    unsigned char ch;
    int i=0;
    while(!feof(fpRead)){
        ch = fgetc(fpRead);
        if(ch != EOF){
            ch = ch ^ key[i%64];
            fwrite(&ch,sizeof(ch),1,fpWrite);
            i++;
        }
    }
    printf("File decrypted successfully!\n");
    fclose(fpRead);
    fclose(fpWrite);
}

int main(){
    int choice;
    char fileName[50];
    printf("Welcome to File Encryption/Decryption program\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    printf("Enter file name (with extension): ");
    scanf("%s",fileName);
    switch(choice){
        case 1:
            encryptFile(fileName);
            break;
        case 2:
            decryptFile(fileName);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}