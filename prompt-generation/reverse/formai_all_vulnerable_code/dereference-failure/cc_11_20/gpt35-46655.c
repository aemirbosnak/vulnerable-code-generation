//FormAI DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//Function to generate QR code
void generateQRCode(char* data, int version, int level){

    //Declare necessary variables
    int size = version * 4 + 17;
    char** QRCode = (char**)malloc(size * sizeof(char*));
    for(int i=0; i<size; i++){
        QRCode[i] = (char*)malloc(size * sizeof(char));
        memset(QRCode[i], ' ', size);
    }

    //Insert finder patterns
    for(int i=0; i<3; i++){
        QRCode[i][0] = QRCode[0][i] = QRCode[i][2] = QRCode[2][i] = '#';
        QRCode[size-i-1][0] = QRCode[size-1][i] = QRCode[size-i-3][2] = QRCode[size-3][i] = '#';
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            QRCode[size-i-1][size-j-1] = QRCode[size-j-1][size-i-1] = '#';
        }
    }
    
    //Encode data
    int x = size-1;
    int y = size-1;
    int dirY = -1;
    int posX = 0;
    int posY = 0;
    int index = 0;
    while(posY < strlen(data)){

        //Insert timing pattern
        if(posX == 6){
            posX++;
        }
        if(posY == 6){
            posY++;
        }

        //Insert and encode data
        if(QRCode[x][y] == ' '){
            if(data[posY] == '1'){
                QRCode[x][y] = '#';
            }else{
                QRCode[x][y] = '*';
            }
            posY++;
            index++;
        }

        //Change direction
        if(x==0 && dirY==-1){
            x += 1;
            dirY = 1;
        }else if(x==size-1 && dirY==1){
            x -= 1;
            dirY = -1;
        }else if(dirY == -1 && (y==0 || QRCode[x][y-1]!=' ')){
            x -= 1;
            dirY = -dirY;
        }else if(dirY == 1 && (y==size-1 || QRCode[x][y+1]!=' ')){
            x -= 1;
            dirY = -dirY;
        }else{
            y += dirY;
        }

        //Insert format information and version information
        if(index == 8){
            for(int i=1; i<=9; i++){
                if(QRCode[size-i][8] == ' '){
                    QRCode[size-i][8] = '#';
                    QRCode[8][i] = '#';
                }
            }
            index += 2;
        }else if(index == 20){
            for(int i=0; i<6; i++){
                if(QRCode[size-i-1][8] == ' '){
                    QRCode[size-i-1][8] = '#';
                    QRCode[8][i] = '#';
                }
            }
            index += 2;
        }

    }

    //Print QR code
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%c ", QRCode[i][j]);
        }
        printf("\n");
    }
}

//Main function
int main(){
    char data[] = "QR code";
    int version = 1;
    int level = 1;
    generateQRCode(data, version, level);
    return 0;
}