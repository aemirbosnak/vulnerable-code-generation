//FormAI DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char text[1000], tbit[8], stext[1000], key[16], dummy[1000];
    int i, j=0, ch, len, klen, bitpos=0, tlen=0;
    FILE *fp, *fkey, *foutput, *fdummy;

    //Opening Text file
    fp=fopen("image.txt", "r");
    if(fp==NULL)
    {
        printf("\nError in Opening File...");
        exit(1);
    }

    //Reading Text file
    for(i=0; feof(fp)==0; i++)
    {
        ch=fgetc(fp);
        text[i]=ch;
    }
    len=i-1;
    fclose(fp);
    printf("\nText Read from File...");
    printf("\nText : %s", text);

    //Opening Key file
    fkey=fopen("key.txt", "r");
    if(fkey==NULL)
    {
        printf("\nError in Opening File...");
        exit(1);
    }

    //Reading Key file
    for(i=0; feof(fkey)==0; i++)
    {
        ch=fgetc(fkey);
        key[i]=ch;
    }
    klen=i-1;
    fclose(fkey);
    printf("\nKey Read from File...");
    printf("\nKey : %s", key);

    //Make length of both Text and Key same
    if(klen<len)
    {
        printf("\n\nError : Length of Key Should be >= Length of Text...");
        exit(1);
    }
    else
    {
        for(i=0; i<klen; i++)
        {
            if(i<len)
            {
                stext[i]=text[i];
            }
            else
            {
                stext[i]='\0';
            }
        }
    }

    //Opening File to Hide Data into a Image
    fp=fopen("image.bmp", "rb");
    if(fp==NULL)
    {
        printf("\nError in Opening File...");
        exit(1);
    }

    //Skip some Header Bytes of Image
    for(i=0; i<54; i++)
    {
        ch=fgetc(fp);
    }

    //Read, Fix and Then Write Pixel Bytes of Image
    while(feof(fp)==0)
    {
        ch=fgetc(fp);

        //Scan Pixels till Data be hidden
        if(j<klen)
        {
            tlen++;
            for(i=0; i<8; i++)
            {
                tbit[i]=((ch & (1<<i)) >> i);
            }
            stext[j]=stext[j] ^ key[j];
            for(i=0; i<8; i++)
            {
                if(bitpos==0 || bitpos==1 || bitpos==2 || bitpos==3 || bitpos==4 || bitpos==5 || bitpos==6)
                {
                    tbit[bitpos] = ((stext[j] & (1<<i)) >> i);
                    bitpos++;
                }
                else if(bitpos==7)
                {
                    tbit[bitpos] = ((stext[j] & (1<<i)) >> i);
                    bitpos=0;
                    j++;
                }
                ch = ((ch & ~(1<<i)) | (tbit[i]<<i));
            }
        }
        fdummy=fopen("dummy.bin","ab");
        fputc(ch, fdummy);
        fclose(fdummy);
    }
    fclose(fp);

    //Opening Dummy File which have our Data
    fdummy=fopen("dummy.bmp","rb");
    if(fdummy==NULL)
    {
        printf("\n\nError : Data Hiding Failed...");
        exit(1);
    }

    //Creating Output File which will have our Data
    foutput=fopen("output.bmp","wb");
    if(foutput==NULL)
    {
        printf("\n\nError in Opening File...");
        exit(1);
    }

    //Copy Header of Image
    for(i=0; i<54; i++)
    {
        ch=fgetc(fdummy);
        fputc(ch, foutput);
    }

    //Read and Then Write Data Bytes
    while(feof(fdummy)==0)
    {
        ch=fgetc(fdummy);
        fputc(ch, foutput);
    }

    printf("\n\nData Hided Successfully...");
    fclose(fdummy);
    fclose(foutput);
    return 0;
}