//FormAI DATASET v1.0 Category: QR code generator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<math.h>

#define QR_SIZE 21 //size of QR code
#define BLACK 1
#define WHITE 0

//function prototypes
void display_qr(uint8_t QR[][QR_SIZE]);
void generate_qr_code(char message[], uint8_t QR[][QR_SIZE], int message_size);

int main()
{
    char message[100]; //message to be converted into QR code
    printf("Enter your message for QR Code:\n");
    scanf("%[^\n]",message); //read whole string with spaces from user
    
    uint8_t QR[QR_SIZE][QR_SIZE]; //array containing QR code
    memset(QR, WHITE, sizeof(uint8_t)*QR_SIZE*QR_SIZE); //initialize QR code with all white pixels
    
    //convert message into QR code
    generate_qr_code(message, QR, strlen(message));
    
    //display QR code
    display_qr(QR);
    
    return 0;
}

//function to display QR code
void display_qr(uint8_t QR[][QR_SIZE])
{
    printf("\nQR Code:\n\n");
    for(int i=0; i<QR_SIZE; i++)
    {
        for(int j=0; j<QR_SIZE; j++)
        {
            if(QR[i][j]==BLACK)
                printf("  ");
            else
                printf("██");
        }
        printf("\n");
    }
}

//function to generate QR code from message
void generate_qr_code(char message[], uint8_t QR[][QR_SIZE], int message_size)
{
    int bit_count = 0; //number of bits in message bit stream
    
    //convert message to bit stream
    uint8_t *message_bits = (uint8_t*)malloc(sizeof(uint8_t)*message_size*8 + 1);
    memset(message_bits, 0, sizeof(uint8_t)*message_size*8 + 1);
    
    for(int i=0; i<message_size; i++)
    {
        uint8_t ascii_value = (uint8_t)message[i];
        for(int j=7; j>=0; j--)
        {
            uint8_t bit_value = (ascii_value >> j) & 1;
            message_bits[bit_count++] = bit_value;
        }
    }
    
    //pad bit stream with zeros
    if(bit_count%8 != 0)
    {
        int pad_size = 8 - bit_count%8;
        for(int i=0; i<pad_size; i++)
            message_bits[bit_count++] = 0;
    }
    
    //append message length in bit stream
    uint8_t *length_bits = (uint8_t*)malloc(sizeof(uint8_t)*14);
    memset(length_bits, 0, sizeof(uint8_t)*14);
    
    int length = bit_count/8;
    for(int i=0; i<14; i++)
    {
        uint8_t bit_value = (length >> (13-i)) & 1;
        length_bits[i] = bit_value;
    }
    
    uint8_t *data_bits = (uint8_t*)malloc(sizeof(uint8_t)*bit_count + 1);
    memset(data_bits, 0, sizeof(uint8_t)*bit_count + 1);
    
    memcpy(data_bits, length_bits, sizeof(uint8_t)*14);
    memcpy(data_bits + 14, message_bits, sizeof(uint8_t)*bit_count);
    
    //arrange data bits into QR code
    int row = QR_SIZE - 1;
    int col = QR_SIZE - 1;
    int bit_index = bit_count + 14 - 1;
    int bit_count_per_row = QR_SIZE*8;
    
    //align pattern
    QR[6][8] = BLACK;
    QR[8][8] = BLACK;
    QR[9][8] = BLACK;
    QR[10][8] = BLACK;
    QR[11][8] = BLACK;
    QR[12][8] = BLACK;
    QR[8][13] = BLACK;
    QR[8][14] = BLACK;
    QR[8][15] = BLACK;
    QR[8][16] = BLACK;
    QR[8][17] = BLACK;
    QR[8][18] = BLACK;
    QR[6][13] = BLACK;
    QR[5][14] = BLACK;
    QR[4][15] = BLACK;
    QR[3][16] = BLACK;
    QR[2][17] = BLACK;
    QR[1][18] = BLACK;
    
    //place data bits in QR code
    while(bit_index >= 0)
    {
        //upward direction
        for(; row>=0 && col>=0; row--, col--)
        {
            if(row == 6 && (col == 9 || col == 8))
                continue; //avoid putting bits in alignment pattern
            
            if(QR[row][col]!=0)
                continue; //already occupied
            
            QR[row][col] = data_bits[bit_index--];
            if(bit_index < 0)
                break;
        }
        row += 1;
        col += 2;
        
        //downward direction
        for(; row<QR_SIZE && col>=0; row++, col--)
        {
            if(row == 9 && col == 8)
                continue; //avoid putting bit in alignment pattern
            
            if(QR[row][col]!=0)
                continue; //already occupied
            
            QR[row][col] = data_bits[bit_index--];
            if(bit_index < 0)
                break;
        }
        row -= 2;
        col += 1;
        
        //upward direction
        for(; row>=0 && col<QR_SIZE; row--, col++)
        {
            if(row == 6 && col == 8)
                continue; //avoid putting bit in alignment pattern
            
            if(QR[row][col]!=0)
                continue; //already occupied
            
            QR[row][col] = data_bits[bit_index--];
            if(bit_index < 0)
                break;
        }
        row += 1;
        col += 2;
        
        //downward direction
        for(; row<QR_SIZE && col<QR_SIZE; row++, col++)
        {
            if(QR[row][col]!=0)
                continue; //already occupied
            
            QR[row][col] = data_bits[bit_index--];
            if(bit_index < 0)
                break;
        }
        row -= 2;
        col += 1;
        
        if(row == 6 && col == QR_SIZE-7)
            col -= 1; //avoid putting bit in alignment pattern
    }
    
    free(message_bits);
    free(length_bits);
    free(data_bits);
}