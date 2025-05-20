//FormAI DATASET v1.0 Category: QR code generator ; Style: recursive
#include<stdio.h>

int findCharacterIndex(char c) //Returns the index of the character in the alphanumeric table
{
    if(c >= '0' && c <= '9')
        return c-'0'+1;
    else if(c >= 'A' && c <= 'Z')
        return c-'A'+11;
    else if(c >= 'a' && c <= 'z')
        return c-'a'+37;
    else if(c == ' ')
        return 0;
    else
        return -1;
}

char findCharacterFromIndex(int index) //Returns the character corresponding to the index in the alphanumeric table
{
    if(index >= 1 && index <= 10)
        return (char)(index+'0'-1);
    else if(index >= 11 && index <= 36)
        return (char)(index+'A'-11);
    else if(index >= 37 && index <= 62)
        return (char)(index+'a'-37);
    else if(index == 0)
        return ' ';
    else
        return '\0';
}

void generateQRCode(char* code, int size, int index, int level) //Recursive function to generate QR code
{
    int i, j;
    int data[64][64] = {0}; //Initialize a 64x64 2D array to store the QR code data
    
    //Module indicator and timing patterns
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            data[i][j] = 2;
    for(i = 7; i < 14; i++)
    {
        data[i][6] = 2;
        data[6][i] = 2;
    }
    
    //Format and version information
    for(i = 0; i < 8; i++)
    {
        data[size-8+i][8] = 2;
        data[8][i] = 2;
    }
    
    //Alignment patterns and separator lines
    if(level < 2)
    {
        for(i = 4; i < size-4; i += 8)
            for(j = 4; j < size-4; j += 8)
            {
                int k, l;
                for(k = -2; k <= 2; k++)
                    for(l = -2; l <= 2; l++)
                        data[i+k][j+l] = 2;
                for(k = -1; k <= 1; k++)
                    for(l = -1; l <= 1; l++)
                        data[i+k][j+l] = 0;
            }
    }
    else
    {
        for(i = 3; i < size-3; i += 4)
            for(j = 3; j < size-3; j += 4)
            {
                int k, l;
                for(k = -1; k <= 2; k++)
                    for(l = -1; l <= 2; l++)
                        data[i+k][j+l] = 2;
                for(k = 0; k <= 1; k++)
                    for(l = 0; l <= 1; l++)
                        data[i+k][j+l] = 0;
            }
    }
    
    //Data encoding and masking
    int direction = 0; //Current direction of the pattern
    int row = size-1, col = size-1; //Current position on the data matrix
    while(index >= 0 && row >= 0 && col >= 0)
    {
        int x = row, y = col;
        switch(direction)
        {
            case 0: y--; break;
            case 1: x--; break;
            case 2: y++; break;
            case 3: x++; break;
        }
        if(x >= 0 && x < size && y >= 0 && y < size && data[x][y] != 2 && index >= 0) //If the current position is valid and not already assigned
        {
            int bit = index%2; //Get the next bit from the data stream
            index /= 2;
            if(data[x][y] == 1)
                bit = !bit; //XOR with existing bit at position
            data[x][y] = bit; //Assign the bit value
        }
        //Change direction if necessary
        if(row == col || (row < col && row+col == size-1) || (row > col && row+col == size))
            direction = (direction+1)%4;
        //Move to the next position
        switch(direction)
        {
            case 0: col--; break;
            case 1: row--; break;
            case 2: col++; break;
            case 3: row++; break;
        }
    }
    
    //Masking the data matrix
    int mask = 0;
    int minScore = -1; //Minimum penalty score among all masks
    for(i = 0; i < 8; i++)
    {
        int score = 0;
        int maskData[64][64];
        for(j = 0; j < size; j++)
            for(int k = 0; k < size; k++)
            {
                maskData[j][k] = data[j][k];
                if((j+k)%2 == mask) //Apply mask pattern
                    maskData[j][k] = !maskData[j][k];
            }
        
        //Calculate penalty score
        int count = 0;
        int prevBit = -1;
        for(j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                if(j > 2 && k > 2)
                {
                    int bit = maskData[j][k];
                    if(bit == prevBit)
                        count++;
                    else
                    {
                        if(count >= 5)
                            score += count+2;
                        count = 1;
                        prevBit = bit;
                    }
                }
            }
        }
        if(count >= 5)
            score += count+2;
        count = 1;
        prevBit = -1;
        for(j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                if(j > 2 && k > 2)
                {
                    int bit = maskData[k][j];
                    if(bit == prevBit)
                        count++;
                    else
                    {
                        if(count >= 5)
                            score += count+2;
                        count = 1;
                        prevBit = bit;
                    }
                }
            }
        }
        if(count >= 5)
            score += count+2;
        int numDark = 0;
        for(j = 0; j < size; j++)
            for(int k = 0; k < size; k++)
                if(maskData[j][k] == 1)
                    numDark++;
        int percentDark = (int)((double)numDark/(double)(size*size)*100.0+0.5);
        int o1 = percentDark/5-10;
        int o2 = (percentDark+5)/5-10;
        score += (o1<0? -o1 : o1) < (o2<0? -o2 : o2) ? o1*10 : o2*10;
        if(minScore == -1 || score < minScore)
        {
            minScore = score;
            mask = i;
        }
    }
    for(j = 0; j < size; j++)
        for(int k = 0; k < size; k++)
            if((j+k)%2 == mask) //Apply final mask pattern
                data[j][k] = !data[j][k];
    
    //Print QR code
    printf("\n");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            char c = findCharacterFromIndex(data[i][j]);
            if(c == '\0')
                printf("  ");
            else
                printf("%c%c", c, c);
        }
        printf("\n");
    }
    
    if(index >= 0) //If there is more data to encode
        generateQRCode(code, size+2, index, level); //Increase size of QR code and generate again
}

int main()
{
    char code[1000];
    printf("Enter message to be encoded:\n");
    scanf("%[^\n]", code);
    int size = 21; //Minimum size of QR code (version 1)
    int level = 0; //Error correction level (L = 0, M = 1, Q = 2, H = 3)
    int index = 0;
    int i;
    for(i = 0; code[i] != '\0'; i++) //Convert message to bitstream
    {
        int val = findCharacterIndex(code[i]);
        if(val != -1)
        {
            int j;
            for(j = 5; j >= 0; j--)
            {
                int bit = (val>>j)&1;
                index = (index<<1)|bit;
            }
        }
    }
    generateQRCode(code, size, index, level);
    return 0;
}